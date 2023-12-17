#pragma once

#include "ray.hpp"
#include "hittable.hpp"
#include "utility.hpp"

/**
 * @file material.hpp
 * @author Verneri Hakkarainen
 * @brief The material class represents materials used for ray tracing.
 * Heavily inspired by Peter Shirley https://raytracing.github.io/v3/books/RayTracingInOneWeekend.html
 * @version 0.1
 * @date 2023-11-17
 * 
 * @copyright Copyright (c) 2023
 */


/**
 * @class material
 * @brief virtual class for all the materials.
 * 
 */
class material {
    public:
        virtual color emitted(double u, double v, const point3& p) const {
            return color(0,0,0);
        }
        virtual bool scatter(
            const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
        ) const = 0;
};

/**
 * @class lambertian
 * @brief Class representing Lambertian diffusion.
 */
class lambertian : public material {
    public:

        /**
         * @brief Constructor for Lambertian material.
         * 
         * @param a Albedo color.
         */
        lambertian(const color& a);

        /**
         * @brief Calculates the correct scatter of the vector for lambertian material.
         * 
         * @param r_in The incoming vector
         * @param rec hit record of hit point.
         * @param attenuation The color change of the ray after hitting.
         * @param scattered The scattered ray.
         * @return true if hit.
         * @return false otherwise.
         */
        virtual bool scatter(
            const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
        ) const override;

    private:
        color albedo;
};

/**
 * @class metal
 * @brief Class representing metal material.
 */
class metal : public material {
    public:

        /**
        * @brief Constructor for metal material.
        * 
        * @param a Albedo color.
        * @param f Fuzziness factor.
        */
        metal(const color& a, double f);

        /**
         * @brief Calculates the correct scatter of the vector for metal material. Mertal should acct like a mirror.
         * 
         * 
         * @param r_in The incoming vector
         * @param rec hit record of hit point.
         * @param attenuation The color change of the ray after hitting.
         * @param scattered The scattered ray.
         * @return true if hit.
         * @return false otherwise.
         */
        virtual bool scatter(
            const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
        ) const override;

    private:
        color albedo;
        double fuzz;
};

/**
 * @class dielectric
 * @brief Class representing dielectric material.
 */
class dielectric : public material {
    public: 

        /**
         * @brief Constructor for dielectric material.
         * 
         * @param index_of_refraction Index of refraction.
         */
        dielectric(double index_of_reftraction); 

        /**
         * @brief Calculates the correct scatter of the vector for dielectric material. This should look like glass.
         * 
         * @param r_in The incoming vector
         * @param rec hit record of hit point.
         * @param attenuation The color change of the ray after hitting.
         * @param scattered The scattered ray.
         * @return true if hit.
         * @return false otherwise.
         */
        virtual bool scatter(
            const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
        ) const override;

    private: 
        double ir; // index of refraction 

        /**
        * @brief Calculate reflectance using Schlick's approximation.
        * 
        * @param cosine Cosine of the angle of incidence.
        * @param ref_idx Index of refraction.
        * @return Reflectance value.
        */

        static double reflectance(double cosine, double ref_idx) {
            auto r0 = (1-ref_idx) / (1+ref_idx);
            r0 = r0*r0; 
            return r0 + (1-r0)*pow((1-cosine),5);
        }
};

/**
 * @class diffuse_light
 * @brief Represents a light source material.
 */
class diffuse_light : public material  {
    public:

        /**
         * @brief Contructor with a color
         * @param a Given color for the light.
         */
        diffuse_light(color c);

        virtual bool scatter(
            const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
        ) const override;

        /**
         * @brief Emits light.
         * 
         * @param u Coordinate of object surface.
         * @param v Coordinate of object surface.
         * @param p Coordinate of the 3D world.
         * @return Coordinates for the light ray.
         */
        virtual color emitted(double u, double v, const point3& p) const override;

    private:
        shared_ptr<color> emit;
};