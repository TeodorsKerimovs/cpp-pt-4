/**
 * @file vec3_tests.cpp
 * @author Teodors Kerimovs
 * @brief This is a unit test file, that is testing vec3 class. It is executed by cmake. 
 * @version 0.1
 * @date 2023-11-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <gtest/gtest.h>
#include "../src/vec3.hpp"

TEST(vec3_tests, DefaultConstructor) {
    vec3 v; // Create a vec3 object using the default constructor
    // Check if the elements are set to {0, 0, 0}
    EXPECT_EQ(v.x(), 0.0);
    EXPECT_EQ(v.y(), 0.0);
    EXPECT_EQ(v.z(), 0.0);
}


TEST(vec3_tests, ThreeParameterConstructor) {
    vec3 v(1.0, 2.0, 3.0);

    // Check if the elements are set to the provided values
    EXPECT_EQ(v.e[0], 1.0);
    EXPECT_EQ(v.e[1], 2.0);
    EXPECT_EQ(v.e[2], 3.0);
}

TEST(vec3_tests, AccessorMethods) {
    vec3 v(4.0, 5.0, 6.0);

    // Use accessor methods to get individual components and test them
    EXPECT_EQ(v.x(), 4.0);
    EXPECT_EQ(v.y(), 5.0);
    EXPECT_EQ(v.z(), 6.0);
}

TEST(vec3_tests, NegationOperator) {
    vec3 v(1.0, -2.0, 3.0);
    vec3 negated_v = -v; // Use the unary negation operator

    // Check if the components of the negated vector are negated correctly
    EXPECT_EQ(negated_v.x(), -1.0);
    EXPECT_EQ(negated_v.y(), 2.0);
    EXPECT_EQ(negated_v.z(), -3.0);
}

TEST(vec3_tests, CompoundOperators) {
    vec3 v(1.0, 2.0, 3.0);
    vec3 u(3.0, 4.0, 5.0);

    // Test compound addition assignment operator
    v += u;
    EXPECT_EQ(v[0], 4.0);
    EXPECT_EQ(v[1], 6.0);
    EXPECT_EQ(v[2], 8.0);

    // Test compound multiplication assignment operator
    u *= 2.0;
    EXPECT_EQ(u[0], 6.0);
    EXPECT_EQ(u[1], 8.0);
    EXPECT_EQ(u[2], 10.0);

    // Test compound division assignment operator
    u /= 2.0;
    EXPECT_EQ(u[0], 3.0);
    EXPECT_EQ(u[1], 4.0);
    EXPECT_EQ(u[2], 5.0);
}

TEST(vec3_tests, UtilityFunctions) {
    vec3 v(1.0, 2.0, 3.0);

    // Test length and length_squared functions
    EXPECT_DOUBLE_EQ(v.length_squared(), 14.0);
    EXPECT_DOUBLE_EQ(v.length(), sqrt(14.0));

    // Test cross product function
    vec3 u(2.0, 3.0, 4.0);
    vec3 cross_result = cross(v, u);
    EXPECT_EQ(cross_result[0], -1.0);
    EXPECT_EQ(cross_result[1], 2.0);
    EXPECT_EQ(cross_result[2], -1.0);

    // Test unit_vector function
    vec3 unit_v = unit_vector(v);
    EXPECT_DOUBLE_EQ(unit_v.length(), 1.0);
}