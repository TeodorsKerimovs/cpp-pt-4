#pragma once
#include "ray.hpp"
#include "interval.hpp"
class material;

/**
 * @class hit_record
 * @brief Stores values related to a hit.
 */
class hit_record {
  public:
    point3 p; /**< Position of the hit point.  */
    vec3 normal; /**< The normal of object surface at the hit point. */
    shared_ptr<material> mat_ptr; /**< Pointer to the object material. */
    double t; /**< The size of t or the length when hit. */
    double u, v; /**< Surface coordinates of the object. */
    bool front_face; /**< Holds information about whether the ray is coming from outside (true). */

    /**
     * @brief Sets the nomal for the surface of the object. And also checks if the ray is coming from the outside of object and changes front_face accordingly.
     *
     *
     * @param r The coming ray.
     * @param outward_normal The outward normal of the surface.
     */
    void set_face_normal(const ray& r, const vec3& outward_normal); 
};


/**
 * @class hittable
 * @brief a base class for different kind of objects.
 */
class hittable {
  public:
    virtual ~hittable() = default;

    /**
     * @brief Chekcs if ray hits. And updates hit record.
     *
     * @param r The coming ray.
     * @param ray_t The interval to be checked for intersection.
     * @param rec The hit_record of the possible hit
     */
    virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;
};
