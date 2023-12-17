#pragma once

#include "rect.hpp"
#include "hittable_list.hpp"

/**
 * @class box
 * @brief Represents a axis-aligned box in 3D space.
 */
class box : public hittable {
  public: 
    box() {}

    /**
     * @brief Constructs a box with specified parameters.
     * @param p0 Minimum point of the box.
     * @param p1 Maximum point of the box.
     * @param ptr Material of the box.
     */
    box(const point3& p0, const point3& p1, shared_ptr<material> ptr);

   /**
     * @brief Determines if a ray hits the box.
     * 
     * Given a ray, this function checks if it intersects with the box
     * within the specified ray parameter interval.
     *
     * @param r The ray.
     * @param ray_t The valid interval for the ray parameter.
     * @param rec The hit record to be filled if the ray hits the box.
     * @return True if the ray hits the box, false otherwise.
     */
    virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const override; 

  public: 
    point3 box_min;
    point3 box_max;
    hittable_list sides;
};
