#pragma once
#include "hittable.hpp"
#include "vec3.hpp"
#include "interval.hpp"

/**
 * @class sphere
 * @brief Represents a sphere
 * @details This class inherits from the hittable class and defines a sphere with a center, radius, and material.
 */
class sphere : public hittable {
  public:
    /**
     * @brief Constructor for the sphere class.
     * @param _center The center of the sphere.
     * @param _radius The radius of the sphere.
     * @param m A shared pointer to the material of the sphere.
     */
    sphere(point3 _center, double _radius, shared_ptr<material> m);

     /**
         * @brief Determines if a ray hits the sphere.
         * 
         *
         * @param r The ray.
         * @param ray_t The valid interval for the ray parameter.
         * @param rec The hit record to be filled if the ray hits the object.
         * @return True if the ray hits the object, false otherwise.
         */
    bool hit(const ray& r, interval ray_t, hit_record& rec) const override;

  private:
    point3 center;
    double radius;
    shared_ptr<material> mat_ptr;
};
