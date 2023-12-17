/**
 * @file material_tests.cpp
 * @author Verneri Hakkarainen
 * @brief Unit test file for material.hpp 
 * @version 0.1
 * @date 2023-11-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>
#include "../src/material.hpp"


TEST(material_tests, lambertianScatter) {
    
    lambertian lam(color(100,100,100));

    hit_record hr;
    hr.p = vec3(0.0, -1, 0.0);
    hr.normal = vec3(0, 1, 0);

    ray r(vec3(-1, 1, 0), vec3(0, -1, 0));

    color attenuation;
    ray scattered = ray();

    bool result = lam.scatter(r, hr, attenuation, scattered);

    // making shure the function works.
    ASSERT_TRUE(result);

    // the scattered.direction() ray should be on a sphere thats radius is 1.
    double scatteredRadius = scattered.direction().length();
    bool fits = -0.998 < scatteredRadius < 1.002;
    ASSERT_TRUE(fits);
}


TEST(material_tests, metalScatter) {

    metal met(color(1,1,1), 0.5);

    hit_record hr;
    hr.p = vec3(0.0, -1, 0.0);
    hr.normal = vec3(0, 1, 0);

    ray r(vec3(-2, 2, 0), vec3(2, -3, 0));

    color attenuation;
    ray scattered = ray();

    bool result = met.scatter(r, hr, attenuation, scattered);

    // making shure the function works. Should return true with reasonable parameters.
    ASSERT_TRUE(result);

    // the scattered ray should be in place of [0.5547,0.8320,0]. When fuzz is applied the given coordinate can have its values changed by +- 0.5. since f is 0.5.
    vec3 sv = scattered.direction();

    EXPECT_NEAR(sv[0],0.554700196225,0.5);
    EXPECT_NEAR(sv[1],0.832050294338,0.5);
    EXPECT_NEAR(sv[2],0,0.5);
}


TEST(material_tests, diaelectricScatter) {

    dielectric die(1.5);

    hit_record hr;
    hr.p = vec3(0.0, -1, 0.0);
    hr.normal = vec3(0, 1, 0);
    hr.front_face = true;

    ray r(vec3(-2, 2, 0), vec3(2, -3, 0));

    color attenuation;
    ray scattered = ray();

     bool result = die.scatter(r, hr, attenuation, scattered);

    //should work
    ASSERT_TRUE(result);

    vec3 sv = scattered.direction();

    EXPECT_NEAR(sv[0],0.3698,0.0005);
    EXPECT_NEAR(sv[1],-0.929112,0.0005);
    EXPECT_NEAR(sv[2],0,0.0005);
}


TEST(material_tests, diffuse_lightEmit) {

    diffuse_light light(color(100,100,100));

    color result = light.emitted(100,100, vec3(0,0,0));

    EXPECT_EQ(result[0], 100);
    EXPECT_EQ(result[1], 100);
    EXPECT_EQ(result[2], 100);
}