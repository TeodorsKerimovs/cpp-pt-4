#pragma once

#include "vec3.hpp"
#include "interval.hpp"
#include "fstream"
#include "ray.hpp"
#include "hittable_list.hpp"
#include "camera.hpp"
#include "material.hpp"
#include "interval.hpp"
#include "fstream"
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

/**
 * @struct PixelInfo
 * @brief Represents one pixel in the picture.
 * @details Holds information about the pixel, including its position (x, y) and color.
 */
struct PixelInfo {
    int x;
    int y; 
    color pixel_color;
};

/**
 * @brief Calculates the color of a given ray in the scene.
 * @param r The ray to calculate the color for.
 * @param background The background color.
 * @param world The scene.
 * @param depth The recursion depth for ray tracing.
 * @return The color of the ray.
 */
color ray_color(const ray& r, const color& background, const hittable& world, int depth, bool skylight);


/**
 * @brief Renders the scene with multithreading or not.
 * @param image_width The width of the output image.
 * @param image_height The height of the output image.
 * @param samples_per_pixel The number of samples per pixel.
 * @param max_depth The maximum recursion depth for ray tracing.
 * @param cam The camera used to view the scene.
 * @param world The list of objects in the scene.
 * @param background The background color of the scene.
 */
void render(int image_width, int image_height, int samples_per_pixel, int max_depth, camera cam, hittable_list& world, color background, bool skylight);