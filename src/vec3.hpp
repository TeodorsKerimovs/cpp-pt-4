#pragma once
/**
 * @file vec3.hpp
 * @author Teodors Kerimovs (teodors.kerimovs@gmail.com)
 * @brief A C++ header file defining a 3D vector class and related utility functions. 
 * Heavily inspired by Peter Shirley https://raytracing.github.io/v3/books/RayTracingInOneWeekend.html
 * @version 0.1
 * @date 2023-11-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <cmath>
#include <iostream>
#include "utility.hpp"



using std::sqrt;
/**
 * @class vec3
 * @brief A class representing a 3D vector with x, y, and z components.
 */
class vec3 {
    public:
    /**
     * @brief Default constructor for a vec3, initializes all components to zero.
     */
        vec3() : e{0,0,0} {}
    /**
     * @brief Constructor to create a vec3 with specified components.
     * @param e0 The x-component.
     * @param e1 The y-component.
     * @param e2 The z-component.
     */        
        vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}
    /**
     * @brief Get the x-component of the vec3.
     * @return The x-component as a double.
     */
        double x() const { return e[0]; }
    /**
     * @brief Get the y-component of the vec3.
     * @return The y-component as a double.
     */        
        double y() const { return e[1]; }
    /**
     * @brief Get the z-component of the vec3.
     * @return The z-component as a double.
     */        
        double z() const { return e[2]; }

    /**
     * @brief Unary negation operator, returns the negation of the vector.
     * @return The negated vector as a vec3.
     */
        vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
        
    /**
     * @brief Array subscript operator to access vector components.
     * @param i The index (0 for x, 1 for y, 2 for z).
     * @return The component at the specified index as a double (const version).
     */        
        double operator[](int i) const { return e[i]; }
        
    /**
     * @brief Array subscript operator to access vector components (non-const version).
     * @param i The index (0 for x, 1 for y, 2 for z).
     * @return A reference to the component at the specified index as a double.
     */        
        double& operator[](int i) { return e[i]; }


    /**
     * @brief Compound addition assignment operator for vector addition.
     * @param v The vector to be added to this vector.
     * @return A reference to this vector after addition.
     */
        vec3& operator+=(const vec3 &v);

    /**
     * @brief Compound multiplication assignment operator for scalar multiplication.
     * @param t The scalar value to multiply this vector.
     * @return A reference to this vector after multiplication.
     */
        vec3& operator*=(const double t);

    /**
     * @brief Compound division assignment operator for scalar division.
     * @param t The scalar value to divide this vector.
     * @return A reference to this vector after division.
     */
        vec3& operator/=(const double t) {
            return *this *= 1/t;
        }

    /**
     * @brief Calculate the length (magnitude) of the vector.
     * @return The length of the vector as a double.
     */
        double length() const {
            return sqrt(length_squared());
        }

    /**
     * @brief Calculate the squared length (magnitude) of the vector.
     * @return The squared length of the vector as a double.
     */
        double length_squared() const {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }
    
    /**
     * @brief creates a vec3 with random values from [0,1)
     * 
     * @return vec3 
     */
    inline static vec3 random() {
    return vec3(random_double(), random_double(), random_double());
    }

    /**
     * @brief creates a vec3 with ranodom values in chosen range [min, max)
     * 
     * @param min 
     * @param max 
     * @return vec3 
     */
    inline static vec3 random(double min, double max) {
        return vec3(random_double(min,max), random_double(min,max), random_double(min,max));
    }

    inline bool operator==(const vec3& rhs) const {
        return e[0] == rhs.e[0] && e[1] == rhs.e[1] && e[2] == rhs.e[2];
    }

    bool near_zero() const;

    public:
        double e[3]; // Components of the vec3.
};

// Type aliases for vec3
using point3 = vec3;   // 3D point
using color = vec3;    // RGB color



// vec3 Utility Functions
/**
 * @brief Overloaded output stream operator to print a vec3.
 * @param out The output stream.
 * @param v The vec3 to be printed.
 * @return The output stream after printing the vec3.
 */
std::ostream& operator<<(std::ostream &out, const vec3 &v);

/**
 * @brief Overloaded addition operator for vector addition.
 * @param u The first vector.
 * @param v The second vector.
 * @return The result of adding the two vectors as a vec3.
 */
vec3 operator+(const vec3 &u, const vec3 &v);

/**
 * @brief Overloaded subtraction operator for vector subtraction.
 * @param u The first vector.
 * @param v The second vector.
 * @return The result of subtracting the second vector from the first as a vec3.
 */
vec3 operator-(const vec3 &u, const vec3 &v);

/**
 * @brief Overloaded multiplication operator for component-wise vector multiplication.
 * @param u The first vector.
 * @param v The second vector.
 * @return The result of multiplying the two vectors component-wise as a vec3.
 */
vec3 operator*(const vec3 &u, const vec3 &v);

/**
 * @brief Overloaded multiplication operator for scalar multiplication.
 * @param t The scalar value.
 * @param v The vector to be multiplied.
 * @return The result of multiplying the vector by the scalar as a vec3.
 */
vec3 operator*(double t, const vec3 &v);

/**
 * @brief Overloaded multiplication operator for scalar multiplication (reversed order).
 * @param v The vector to be multiplied.
 * @param t The scalar value.
 * @return The result of multiplying the vector by the scalar as a vec3.
 */
vec3 operator*(const vec3 &v, double t);

/**
 * @brief Overloaded division operator for scalar division.
 * @param v The vector to be divided.
 * @param t The scalar value.
 * @return The result of dividing the vector by the scalar as a vec3.
 */
vec3 operator/(vec3 v, double t);

/**
 * @brief Calculate the dot product of two vectors.
 * @param u The first vector.
 * @param v The second vector.
 * @return The dot product of the two vectors as a double.
 */
double dot(const vec3 &u, const vec3 &v);
/**
 * @brief Calculate the cross product of two vectors.
 * @param u The first vector.
 * @param v The second vector.
 * @return The cross product of the two vectors as a vec3.
 */
vec3 cross(const vec3 &u, const vec3 &v);

/**
 * @brief Calculate the unit vector (normalized vector) of a given vector.
 * @param v The vector to be normalized.
 * @return The unit vector (normalized vector) of the input vector as a vec3.
 */
vec3 unit_vector(vec3 v);


/**
 * @brief chooses a random point inside a unit sphere. Used in reflections of different materials.
 * 
 * @return vec3 
 */
vec3 random_in_unit_sphere();

/**
 * @brief Chooses a random point on the surface unit circle cirlce.
 * 
 * @return vec3 
 */
vec3 random_unit_vector();

/**
 * @brief TODO different kind of diffuse
 * 
 * @param normal 
 * @return ** vec3 
 */
vec3 random_in_hemisphere(const vec3& normal);

vec3 reflect(const vec3& v, const vec3& n);

/**
 * @brief Generates a random point in the unit disk.
 * 
 * This function continues generating points until it finds one within the unit disk.
 * 
 * @return A random point in the unit disk.
 */
vec3 random_in_unit_disk();

/**
 * @brief Computes the refraction direction for a given incident vector (uv),
 *        surface normal (n), and the ratio of refractive indices (etai_over_etat).
 * 
 * This function ensures the cosine of the angle between the incident vector and the normal is within [-1, 1],
 * and then computes the refracted ray using Snell's Law.
 * 
 * @param uv The incident vector.
 * @param n The surface normal.
 * @param etai_over_etat The ratio of refractive indices.
 * @return The refracted ray direction.
 */
vec3 refract(const vec3& uv, const vec3& n, double etai_over_etat);