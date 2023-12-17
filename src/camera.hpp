#pragma once
#include "utility.hpp"
#include "ray.hpp"
#include "vec3.hpp"

/**
 * @file camera.hpp
 * @author Lauri Wilppu (lauri.wilppu@gmail.com)
 * @brief The camera class represents a camera used for ray tracing.
 * Heavily inspired by Peter Shirley https://raytracing.github.io/v3/books/RayTracingInOneWeekend.html
 * @version 0.1
 * @date 2023-11-07
 * 
 * @copyright Copyright (c) 2023
 */

/**
 * @class camera
 * @brief Represents a movable camera in the world.
 */
class camera {
 public:
  /**
   * @brief Constructs a camera with the specified parameters.
   *
   * @param lookfrom The camera's position.
   * @param lookat The point the camera is looking at.
   * @param vup The "up" vector indicating the camera's orientation.
   * @param vfov The vertical field-of-view in degrees.
   * @param aspect_ratio The aspect ratio of the viewport.
   * @param _time0 Time when the shutter opens for blur
   * @param _time1 Time when the shutter closes for blur
   */
  camera(
      point3 lookfrom, 
      point3 lookat, 
      vec3 vup, 
      double vfov, 
      double aspect_ratio,
      double aperture, 
      double focus_dist,
      double _time0,
      double _time1      
      );

  /**
   * @brief Generates a ray from the camera for a given screen position.
   *
   * @param s The horizontal coordinate on the screen (0 to 1).
   * @param t The vertical coordinate on the screen (0 to 1).
   * @return The generated ray.
   */
  ray get_ray(double s, double t) const; 

  /**
   * @brief Gets the origin of the camera.
   * @return The camera's origin point.
   */
  point3 getOrigin() const {
    return origin;
  }

  /**
   * @brief Gets the radius of the lens.
   * @return Lens radius
   */
  double getLensRadius() const {
    return lens_radius;
  }

 private:
  point3 origin;
  point3 lower_left_corner;
  vec3 horizontal;
  vec3 vertical;
  vec3 u, v, w;
  double lens_radius;
  double time0, time1;
};
