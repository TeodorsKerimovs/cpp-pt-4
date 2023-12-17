#pragma once
/**
 * @file ray.hpp
 * @author Teodors Kerimovs (teodors.kerimovs@gmail.com)
 * @class ray
 * @brief A class representing a ray with an origin point and a direction vector. 
 * Heavily inspired by Peter Shirley https://raytracing.github.io/v3/books/RayTracingInOneWeekend.html
 * @version 0.1
 * @date 2023-11-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "vec3.hpp"


class ray {
public:
    /**
     * @brief Default constructor for a ray.
     */
    ray() {}

    /**
     * @brief Constructor to create a ray with an origin and direction.
     * @param origin The origin point of the ray.
     * @param direction The direction vector of the ray.
     * @param time The time, when ray is existing
     */

    ray(const point3& origin, const vec3& direction, double time = 0.0)
        : orig(origin), dir(direction), tm(time)
    {}

    /**
     * @brief Get the origin point of the ray.
     * @return The origin point as a point3.
     */
    point3 origin() const  { return orig; }

    /**
     * @brief Get the direction vector of the ray.
     * @return The direction vector as a vec3.
     */
    vec3 direction() const { return dir; }
   
   /**
     * @brief Get the time of ray appearing.
     * @return The time of ray appearing.
     */
    double time() const    { return tm; }

    /**
     * @brief Compute a point on the ray at a given parameter value.
     * @param t The parameter value that determines the point's position along the ray.
     * @return The point on the ray at the specified parameter value.
     */
    point3 at(double t) const;

public:
    point3 orig; // The origin point of the ray.
    vec3 dir;    // The direction vector of the ray.
    double tm; // Time of vector appearing.
};