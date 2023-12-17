#pragma once


#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>


// Usings

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// Constants
const double pi = 3.1415926535897932385;

// Utility Functions

/**
 * @brief Convert degrees to radians.
 * @param degrees The angle in degrees.
 * @return The corresponding angle in radians.
 */
double degrees_to_radians(double degrees);

/**
 * @brief Clamp a value within a specified range.
 * @param x The value to be clamped.
 * @param min The minimum allowed value.
 * @param max The maximum allowed value.
 * @return The clamped value.
 */
double clamp(double x, double min, double max);

/**
 * @brief Generates a random double in the range [0, 1).
 * @return A random double.
 */
double random_double();

/**
 * @brief Generates a random double in the specified range.
 * @param min The minimum value of the range.
 * @param max The maximum value of the range.
 * @return A random double in the specified range.
 */
double random_double(double min, double max);

/**
 * @brief Generates a random integer in the specified range.
 * @param min The minimum value of the range.
 * @param max The maximum value of the range.
 * @return A random integer in the specified range.
 */
int random_int(int min, int max);
