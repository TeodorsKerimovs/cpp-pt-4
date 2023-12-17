#pragma once
#include <limits>

const double infinity = std::numeric_limits<double>::infinity();


/**
 * @class interval
 * @brief Represents an interval between two points.
 */
class interval {
  public:
    double min, max;  /**< The parameters for min and max.  */

    /**
     * @brief Default constructor with empty interval.
     * 
     */
    interval();

    /**
     * @brief Constructor which sets min and max.
     *  
     * @param _min Min value
     * @param _max Max value
     * 
     */
    interval(double _min, double _max);

    /**
     * @brief Checks if the interval contains certain value within range
     * 
     * @param x The value to be checked for.
     * @return true if contains within range
     * @return false otherwise
     */
    bool contains(double x) const;

    /**
     * @brief Chekcs if x is between the pramaters. Not including min and max.
     * 
     * @param x 
     * @return true if contains
     * @return false otherwise
     */
    bool surrounds(double x) const;

    /**
     * @brief Checks if x is outside parameters and returns closest min or max to it.
     *
     * @param x 
     * @return double
     */
    double clamp(double x) const;
    
    static const interval empty, universe;
};

const static interval empty   (+infinity, -infinity);
const static interval universe(-infinity, +infinity);