#pragma once
#include "hittable.hpp"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

/**
 * @class hittable_list
 * @brief Represents a list of objects the ray can hit.
 */
class hittable_list : public hittable {
  public:
    std::vector<shared_ptr<hittable>> objects; /**< Vector containing shared pointers to hittable objects. */

    /**
     * @brief Default constructor.
     */
    hittable_list() {} 

    /**
     * @brief Constructor with an initial hittable object.
     * @param object The object to be added to the list.
     */
    hittable_list(shared_ptr<hittable> object);

    /**
     * @brief Clears the list of objects.
     */
    void clear();

    /**
     * @brief Adds an object to the end of the list.
     * @param object The object to be added to the list.
     */
    void add(shared_ptr<hittable> object); 
    

    /**
     * @brief Checks if a ray hits an object in the list given the parameters. And updates the record of that object.
     * 
     * @param r The ray.
     * @param ray_t Interval or length of ray to be checked for intersection.
     * @param rec The hit record to be filled if the ray hits an object.
     * @return True if the ray hits any object in the list, false otherwise.
     */
    bool hit(const ray& r, interval ray_t, hit_record& rec) const override;
};
