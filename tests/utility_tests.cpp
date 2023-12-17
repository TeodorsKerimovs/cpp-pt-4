/**
 * @file utility_tests.cpp
 * @author Lauri Wilppu
 * @brief Unit test file for utiltiy.hpp
 * @version 0.1
 * @date 2023-11-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <gtest/gtest.h>
#include "../src/utility.hpp"

TEST(utility_tests, degrees_to_radians) {

  // test degrees_to_radians 
  EXPECT_EQ(degrees_to_radians(180), pi);
  EXPECT_EQ(degrees_to_radians(0), 0);
  EXPECT_NEAR(degrees_to_radians(30.5), 0.532325422 ,0.00000001);
  EXPECT_NEAR(degrees_to_radians(57.43), 1.00234259 ,0.00000001);
}

TEST(utility_tests, clamp) {

  EXPECT_EQ(clamp(1,2,3), 2);
  EXPECT_EQ(clamp(2,2,3), 2);
  EXPECT_EQ(clamp(5,2,3), 3);
  EXPECT_EQ(clamp(-1,1,5), 1);

}

TEST(utility_tests, random_double) {

  double res = random_double();
  EXPECT_GE(res, 0.0); // Check if result is greater than or equal to 0
  EXPECT_LT(res, 1.0); // Check if the result is less than 1.0

  // Check if random_double generates different values
  double res1 = random_double(); 
  double res2 = random_double(); 
  double res3 = random_double(); 
  
  EXPECT_NE(res1, res2);
  EXPECT_NE(res1, res3);
  EXPECT_NE(res3, res2);

  double result = random_double(1.5, 1.6);
  EXPECT_GE(result, 1.5); // Check if result is greater than or equal to 1.5
  EXPECT_LT(result, 1.6); // Check if the result is less than 1.6

  double result1 = random_double(-1,1);
  double result2 = random_double(-1,1); 
  double result3 = random_double(-1,1);

  EXPECT_NE(result1, result2);
  EXPECT_NE(result1, result3);
  EXPECT_NE(result3, result2);  
}

TEST(utility_tests, random_int) {
  EXPECT_EQ(random_int(1,1), 1); 

  int res = random_int(0, 10);
  EXPECT_GE(res, 0); // Check if result is greater than or equal to 0
  EXPECT_LE(res, 10); // Check if the result is less than or equal to 10

  // Check if different values are generated
  int res1 = random_int(-200,200);
  int res2 = random_int(-200,200);
  int res3 = random_int(-200,200);

  EXPECT_NE(res1, res2);
  EXPECT_NE(res1, res3);
  EXPECT_NE(res3, res2);
}