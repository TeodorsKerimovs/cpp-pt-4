/**
 * @file ray.cpp
 * @author Teodors Kerimovs (teodors.kerimovs@gmail.com)
 * @brief Necessary class definitions of ray with an origin point and a direction vector. 
 * @version 0.1
 * @date 2023-12-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "ray.hpp"
/**
 * @brief Compute a point on the ray at a given parameter value.
 * @param t The parameter value that determines the point's position along the ray.
 * @return The point on the ray at the specified parameter value.
 */
point3 ray::at(double t) const {
    return orig + t * dir;
}
