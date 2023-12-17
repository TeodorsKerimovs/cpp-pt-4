/**
 * @file ray_tests.cpp
 * @author Teodors Kerimovs
 * @brief This is a unit test file, that is testing ray class. It is executed by cmake. 
 * @version 0.1
 * @date 2023-12-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>
#include "../src/ray.hpp"

TEST(ray_tests, DefaultConstructor) {
    ray r; // Create a ray object using the default constructor

    // Check if the origin, direction, and time are initialized correctly
    EXPECT_EQ(r.origin(), point3(0.0, 0.0, 0.0));
    EXPECT_EQ(r.direction(), vec3(0.0, 0.0, 0.0)); // Default direction is (0, 0, 1)
    EXPECT_NE(r.time(), 0.0);
}

TEST(ray_tests, ParameterizedConstructor) {
    point3 origin(1.0, 2.0, 3.0);
    vec3 direction(4.0, 5.0, 6.0);
    double time = 2.5;

    ray r(origin, direction, time);

    // Check if the origin, direction, and time are set correctly
    EXPECT_EQ(r.origin(), origin);
    EXPECT_EQ(r.direction(), direction);
    EXPECT_EQ(r.time(), time);
}

TEST(ray_tests, ComputePointAt) {
    ray r(point3(1.0, 2.0, 3.0), vec3(2.0, 3.0, 4.0));

    // Test computing a point on the ray at a specific parameter value
    point3 result = r.at(2.0);
    EXPECT_EQ(result, point3(5.0, 8.0, 11.0));
}