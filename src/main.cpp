#include "ray.hpp"
#include "vec3.hpp"
#include "camera.hpp"
#include "hittable_list.hpp"
#include "sphere.hpp"
#include "material.hpp"
#include "rect.hpp"
#include <chrono>
#include <mutex>
#include <thread>
#include "box.hpp"
#include "moving_sphere.hpp"
#include <iostream>
#include <algorithm>
#include "render.hpp"

#include <fstream>
#include <string>
#include <sstream>
#include "fileread.hpp"

hittable_list example_scene() {

    auto ground = make_shared<lambertian>(color(0.48, 0.83, 0.53));
    auto wall = make_shared<lambertian>(color(0.48, 0.83, 2));

    hittable_list objects;

    objects.add(make_shared<xz_rect>(-1000,1000,-1000,1000, 0.0, ground));
    objects.add(make_shared<xy_rect>(-1000,1000,-1000,1000,1000,wall));

    auto light = make_shared<diffuse_light>(color(7, 7, 7));
    objects.add(make_shared<xz_rect>(123, 423, 147, 412, 554, light));

    auto center1 = point3(400, 400, 200);
    auto center2 = center1 + vec3(30,0,0);
    auto moving_sphere_material = make_shared<lambertian>(color(0.7, 0.3, 0.1));
    objects.add(make_shared<moving_sphere>(center1, center2, 0, 1, 50, moving_sphere_material));

    objects.add(make_shared<sphere>(point3(260, 150, 45), 50, make_shared<dielectric>(1.5)));
    objects.add(make_shared<sphere>(point3(0, 150, 145), 50, make_shared<metal>(color(0.8, 0.8, 0.9), 1.0)));

    return objects;

}

int main(int argc, char* argv[]) {
    bool generate_random_scene_flag;
    // Check if at least one command-line argument is provided
    if (argc < 2) {
        std::cout << "No input scene provided. Ray tracer renders built in scene" << std::endl;
        generate_random_scene_flag = true;
    }
    else{
        std::string filePass = argv[1];
        fileReadList fileReadListNyt;
        fileReadListNyt.performFileRead(filePass);

        // Camera 
        camera cam(fileReadListNyt.cam_frompoint, 
        fileReadListNyt.cam_atpoint, 
        fileReadListNyt.cam_vups, 
        fileReadListNyt.cam_vfov, 
        fileReadListNyt.cam_aspect_ratio, 
        fileReadListNyt.cam_aperature, 
        fileReadListNyt.cam_dist_to_focus, 0.0, 1.0); 

        // Render     
        render(fileReadListNyt.im_w, 
        fileReadListNyt.im_h, 
        fileReadListNyt.im_spp, 
        fileReadListNyt.im_max_depth, 
        cam, 
        fileReadListNyt.objs, 
        fileReadListNyt.im_bc, 
        fileReadListNyt.im_skylight);

    }


    if (generate_random_scene_flag)
    {
        auto world = example_scene();
        bool skylight = false;
        
        // Image
        const auto aspect_ratio = 1.0 / 1.0;
        const int image_width = 600;
        const int image_height = static_cast<int>(image_width / aspect_ratio);
        const int samples_per_pixel = 200;
        const int max_depth = 50;

        // Camera
        point3 lookfrom = point3(478,278,-600);
        point3 lookat = point3( 278, 278, 0);
        vec3 vup(0,1,0);
        auto dist_to_focus = 30;
        auto aperture = 0.1;
        color background = color(0,0,0);
        camera cam(lookfrom, lookat, vup, 40, aspect_ratio, aperture, dist_to_focus, 0.0, 1.0);
        
        //Render 
        render(image_width, image_height, samples_per_pixel, max_depth, cam, world, background, skylight);
    }

}