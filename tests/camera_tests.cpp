/**
 * @file camera_tests.cpp
 * @author Lauri Wilppu
 * @brief This is a unit test file, that is testing camera class. It is executed by cmake. 
 * @version 0.1
 * @date 2023-11-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <gtest/gtest.h>
#include "../src/camera.hpp"

TEST(camera_tests, Constructor) {
  point3 lookfrom(0,2,1);
  point3 lookat(0,0,-1);
  vec3 vup(0,1,0);
  double vfov = 90.0; 
  double aspect_ratio = 16.0 / 9.0;
  double aperture = 10.0;
  double focus_dist = 0.1;

  camera cam(lookfrom, lookat, vup, vfov, aspect_ratio, aperture, focus_dist, 0, 1);

 

  EXPECT_EQ(lookfrom.x(), cam.getOrigin().x());
  EXPECT_EQ(lookfrom.y(), cam.getOrigin().y());
  EXPECT_EQ(lookfrom.z(), cam.getOrigin().z());
  EXPECT_EQ(aperture / 2, cam.getLensRadius());


} 
  // check if generated rays direction is calculated correctly
  /*
  EXPECT_NEAR(r.direction().x(), 0.577350269, 0.00000001);
  EXPECT_NEAR(r.direction().y(), -0.577350269, 0.00000001);
  EXPECT_NEAR(r.direction().z(), -0.577350269, 0.00000001);

  EXPECT_NEAR(r2.direction().x(), 0.112110224, 0.00000001);
  EXPECT_NEAR(r2.direction().y(), -0.250751637, 0.00000001);
  EXPECT_NEAR(r2.direction().z(), -1.36918895, 0.00000001);
  */
