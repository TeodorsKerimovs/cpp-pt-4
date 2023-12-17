#pragma once

#include "hittable.hpp"

/**
 * @class moving_sphere
 * @brief Represents moving sphere.
 */
class moving_sphere : public hittable {
    public:
        moving_sphere() {}

        /**
         * @brief Constructor for the moving_sphere. The moving happens from cen0 to cen1 linearily. _time0 and _time1 are used to calculate the ray intersection point.
         * 
         * @param cen0 start point of the movement.
         * @param cen1 end point of movement.
         * @param _time0 start time of movement.
         * @param _time1 end point of movement.
         * @param r radius of the sphere
         * @param m material of the sphere
         * 
         */
        moving_sphere(
            point3 cen0, point3 cen1, double _time0, double _time1, double r, shared_ptr<material> m)
            : center0(cen0), center1(cen1), time0(_time0), time1(_time1), radius(r), mat_ptr(m)
        {};

        /**
         * @brief Determines if a ray hits the sphere.
         * 
         *
         * @param r The ray.
         * @param ray_t The valid interval for the ray parameter.
         * @param rec The hit record to be filled if the ray hits the object.
         * @return True if the ray hits the box, false otherwise.
         */

        virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const override;  
        
        /**
         * @brief return the center the object. During certain time point.
         * 
         */
        point3 center(double time) const;

    private:
        point3 center0, center1;
        double time0, time1;
        double radius;
        shared_ptr<material> mat_ptr;
};