#include "render.hpp"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../libs/stb_image_write.h"
#include <algorithm>
#include "vec3.hpp"

std::mutex iterationMutex;
std::mutex ioMutex;
int currentIteration = 0;

color ray_color(const ray& r, const color& background, const hittable& world, int depth, bool skylight) {
  hit_record rec;

        if (depth <= 0)
        return color(0,0,0);


    // If the ray hits nothing, return the background color.
    if (!world.hit(r, interval(0.0001, infinity), rec)) {
        if (skylight) {
        vec3 unit_direction = unit_vector(r.direction());
        auto a = 0.5*(unit_direction.y() + 1.0);
        return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
        } else {
            return background;
        }
    }

    ray scattered;
    color attenuation;
    color emitted = rec.mat_ptr->emitted(rec.u, rec.v, rec.p);

    if (!rec.mat_ptr->scatter(r, rec, attenuation, scattered))
        return emitted;

    return emitted + attenuation * ray_color(scattered, background, world, depth-1, skylight);

}

static int getNextIteration() {
    std::lock_guard<std::mutex> lock(iterationMutex);
    return currentIteration++;
}

static void write_to_jpg(const char* f, std::vector<PixelInfo> *PixelInfoList, int samples_per_pixel, int width, int height) {
    // Write the translated [0,255] value of each color component.
    // Make JPG image 
    unsigned char data[width * height * 3];
    static const interval intensity(0.000, 0.999);
    int index = 0;
   
    for (auto &PixelInfo : *PixelInfoList) {
        auto r = PixelInfo.pixel_color.x();
        auto g = PixelInfo.pixel_color.y();
        auto b = PixelInfo.pixel_color.z();
        
        auto scale = 1.0 / samples_per_pixel;
        r = sqrt(scale * r);
        g = sqrt(scale * g);
        b = sqrt(scale * b);
        
        data[index++] = 256 * intensity.clamp(r);
        data[index++] = 256 * intensity.clamp(g);
        data[index++] = 256 * intensity.clamp(b); 
    }

    stbi_write_jpg(f, width, height, 3, data, 100);
}

void render(int image_width, int image_height, int samples_per_pixel, int max_depth, camera cam, hittable_list& world, color background, bool skylight) {
 const char *f = "out.jpg";
    std::cout << "P3" << std::endl << image_width << " " << image_height << std::endl << "255" << std::endl;

    
auto begin = std::chrono::high_resolution_clock::now();

// choose if you want multithreading or not 
#define MT 1
#if MT
    
    std::vector<PixelInfo> PixelInfoList;

    int numThreads = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;
    int totalIterations = image_height * image_width;

    auto processIterations = [&]() {
        while (true) {
            int iteration = getNextIteration();

            if (iteration >= image_height) {
                break;
            }
            std::vector<PixelInfo> rowInfo;

            int j = image_height - iteration; 

            for (int i = 0; i < image_width; ++i) {
                color pixel_color(0 , 0, 0);
                for (int s = 0; s < samples_per_pixel; ++s) {
                    auto u = (i + random_double()) / (image_width-1);
                    auto v = (j + random_double()) / (image_height-1);
                    ray r = cam.get_ray(u,v); 
                    pixel_color += ray_color(r, background ,world, max_depth, skylight);
                }
                rowInfo.push_back({i, j, pixel_color});
            }
                std::cerr << "\rScanlines remaining: " << j - 1 << " " << std::flush;
                std::unique_lock<std::mutex> lock(ioMutex);
                PixelInfoList.insert(PixelInfoList.end(), rowInfo.begin(), rowInfo.end());
        }
    };
    
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(processIterations);
    }

    for (auto& thread : threads) {
        thread.join(); 
    }

    std::sort(PixelInfoList.begin(), PixelInfoList.end(), [](const PixelInfo& a, const PixelInfo& b) {
        return a.y > b.y || (a.y == b.y && a.x < b.x);
    });

    
    write_to_jpg(f, &PixelInfoList, samples_per_pixel, image_width, image_height);
    

#else
    std::vector<PixelInfo> PixelInfoList;

 for (int j = image_height-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << " " << std::flush;
        for (int i = 0; i < image_width; ++i) {
            color pixel_color(0 , 0, 0);
            for (int s = 0; s < samples_per_pixel; ++s) {
            auto u = (i + random_double()) / (image_width-1);
            auto v = (j + random_double()) / (image_height-1);
            ray r = cam.get_ray(u,v); 
            pixel_color += ray_color(r, world, max_depth, skylight);
            }
            PixelInfoList.push_back({i, j, pixel_color});
        }
    }
    write_to_jpg(f, &PixelInfoList, samples_per_pixel, image_width, image_height);

#endif

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    std::cerr << std::endl << "Done.\n Time elapsed: " << elapsed.count() * 1e-9 << " seconds" << std::endl;
}