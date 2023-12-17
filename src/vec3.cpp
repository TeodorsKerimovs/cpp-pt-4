/**
 * @file vec3.cpp
 * @author Teodors Kerimovs (teodors.kerimovs@gmail.com)
 * @brief Cpp files with definitions of vec3 members and non-members
 * @version 0.1
 * @date 2023-12-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "vec3.hpp"

/**
 * @brief Definition of a += operator 
 * 
 * @param v 
 * @return vec3& 
 */
vec3& vec3::operator+=(const vec3 &v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}

/**
 * @brief Definition of an *= operator
 * 
 * @param t 
 * @return vec3& 
 */
vec3& vec3::operator*=(const double t)
{
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;  
}

/**
 * @brief Near_zero bool check
 * 
 * @return true 
 * @return false 
 */
bool vec3::near_zero() const {
    // Return true if the vector is close to zero in all dimensions.
    const auto s = 1e-8;
    return (fabs(e[0]) < s) && (fabs(e[1]) < s) && (fabs(e[2]) < s);
}




// vec3 Utility Functions
/**
 * @brief Overloaded output stream operator to print a vec3.
 * @param out The output stream.
 * @param v The vec3 to be printed.
 * @return The output stream after printing the vec3.
 */
std::ostream& operator<<(std::ostream &out, const vec3 &v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

/**
 * @brief Overloaded addition operator for vector addition.
 * @param u The first vector.
 * @param v The second vector.
 * @return The result of adding the two vectors as a vec3.
 */
vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

/**
 * @brief Overloaded subtraction operator for vector subtraction.
 * @param u The first vector.
 * @param v The second vector.
 * @return The result of subtracting the second vector from the first as a vec3.
 */
vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

/**
 * @brief Overloaded multiplication operator for component-wise vector multiplication.
 * @param u The first vector.
 * @param v The second vector.
 * @return The result of multiplying the two vectors component-wise as a vec3.
 */
vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

/**
 * @brief Overloaded multiplication operator for scalar multiplication.
 * @param t The scalar value.
 * @param v The vector to be multiplied.
 * @return The result of multiplying the vector by the scalar as a vec3.
 */
vec3 operator*(double t, const vec3 &v) {
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

/**
 * @brief Overloaded multiplication operator for scalar multiplication (reversed order).
 * @param v The vector to be multiplied.
 * @param t The scalar value.
 * @return The result of multiplying the vector by the scalar as a vec3.
 */
vec3 operator*(const vec3 &v, double t) {
    return t * v;
}

/**
 * @brief Overloaded division operator for scalar division.
 * @param v The vector to be divided.
 * @param t The scalar value.
 * @return The result of dividing the vector by the scalar as a vec3.
 */
vec3 operator/(vec3 v, double t) {
    return (1/t) * v;
}

/**
 * @brief Calculate the dot product of two vectors.
 * @param u The first vector.
 * @param v The second vector.
 * @return The dot product of the two vectors as a double.
 */
 double dot(const vec3 &u, const vec3 &v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

/**
 * @brief Calculate the cross product of two vectors.
 * @param u The first vector.
 * @param v The second vector.
 * @return The cross product of the two vectors as a vec3.
 */
 vec3 cross(const vec3 &u, const vec3 &v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

/**
 * @brief Calculate the unit vector (normalized vector) of a given vector.
 * @param v The vector to be normalized.
 * @return The unit vector (normalized vector) of the input vector as a vec3.
 */
 vec3 unit_vector(vec3 v) {
    return v / v.length();
}


/**
 * @brief Computes the refraction direction for a given incident vector (uv),
 *        surface normal (n), and the ratio of refractive indices (etai_over_etat).
 * 
 * This function ensures the cosine of the angle between the incident vector and the normal is within [-1, 1],
 * and then computes the refracted ray using Snell's Law.
 * 
 * @param uv 
 * @param n 
 * @param etai_over_etat 
 * @return vec3 
 */
vec3 refract(const vec3& uv, const vec3& n, double etai_over_etat) {
    // Ensure the cosine of the angle between the incident vector and the normal is within [-1, 1].
    auto cos_theta = fmin(dot(-uv, n), 1.0);

    // Compute the refracted ray using Snell's Law.
    vec3 r_out_perp = etai_over_etat * (uv + cos_theta * n);
    vec3 r_out_parallel = -sqrt(fabs(1.0 - r_out_perp.length_squared())) * n;

    // Return the refracted ray direction.
    return r_out_perp + r_out_parallel;
}



/**
 * @brief chooses a random point inside a unit sphere. Used in reflections of different materials.
 * 
 * @return vec3 
 */
vec3 random_in_unit_sphere() {
    while (true) {
        auto p = vec3::random(-1,1);
        if (p.length_squared() >= 1) continue;
        return p;
    }
}

/**
 * @brief Chooses a random point on the surface unit circle cirlce.
 * 
 * @return vec3 
 */
vec3 random_unit_vector() {
    return unit_vector(random_in_unit_sphere());
}

/**
 * @brief TODO different kind of diffuse
 * 
 * @param normal 
 * @return ** vec3 
 */
vec3 random_in_hemisphere(const vec3& normal) {
    vec3 in_unit_sphere = random_in_unit_sphere();
    if (dot(in_unit_sphere, normal) > 0.0) // In the same hemisphere as the normal
        return in_unit_sphere;
    else
        return -in_unit_sphere;
}

vec3 reflect(const vec3& v, const vec3& n) {
    return v - 2*dot(v,n)*n;
}

/**
 * @brief Generates a random point in the unit disk.
 * 
 * This function continues generating points until it finds one within the unit disk.
 * 
 * @return A random point in the unit disk.
 */
vec3 random_in_unit_disk() {
    while (true) {
        // Generate a random point in the xy-plane within the unit square [-1,1]x[-1,1].
        auto p = vec3(random_double(-1, 1), random_double(-1, 1), 0);

        // Check if the generated point is within the unit disk (circle with radius 1).
        if (p.length_squared() < 1) {
            return p;
        }
    }
}
