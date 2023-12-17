#pragma once 

#include "utility.hpp"
#include "hittable.hpp"


/**
 * @class Is a XY aligned rectangle.
 * @brief Represents a rectangle parallel to the xy-plane.
 */
class xy_rect : public hittable {
  public:
    xy_rect() {}

     /**
     * @brief Constructs an xy_rect with specified parameters.
     * @param _x0 Minimum x-coordinate.
     * @param _x1 Maximum x-coordinate.
     * @param _y0 Minimum y-coordinate.
     * @param _y1 Maximum y-coordinate.
     * @param _k z-coordinate of the rectangle.
     * @param mat Material of the rectangle.
     */
    xy_rect(double _x0, double _x1, double _y0, double _y1, double _k, 
      shared_ptr<material> mat);

    /**
     * @brief Determines if a ray hits the rectangle.
     * 
     *
     * @param r The ray.
     * @param ray_t The valid interval for the ray parameter.
     * @param rec The hit record to be filled if the ray hits the object.
     * @return True if the ray hits the object, false otherwise.
     */
    virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const override;

  private: 
    shared_ptr<material> mp;
    double x0, x1, y0, y1, k;
};

/**
 * 
 * @class Is a XZ aligned rectangle.
 * @brief Represents a rectangle parallel to the xz-plane.
 */
class xz_rect : public hittable {
  public: 
    xz_rect() {}

     /**
     * @brief Constructs an xy_rect with specified parameters.
     * @param _x0 Minimum x-coordinate.
     * @param _x1 Maximum x-coordinate.
     * @param _z0 Minimum z-coordinate.
     * @param _z1 Maximum z-coordinate.
     * @param _k y-coordinate of the rectangle.
     * @param mat Material of the rectangle.
     */
    xz_rect(double _x0, double _x1, double _z0, double _z1, double _k,
      shared_ptr<material> mat); 
    
    /**
     * @brief Determines if a ray hits the rectangle.
     * 
     *
     * @param r The ray.
     * @param ray_t The valid interval for the ray parameter.
     * @param rec The hit record to be filled if the ray hits the object.
     * @return True if the ray hits the object, false otherwise.
     */
    virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const override;

  private: 
    shared_ptr<material> mp; 
    double x0, x1, z0, z1, k; 
};

/**
 * 
 * @class Is a YZ aligned rectangle.
 * @brief Represents a rectangle parallel to the yz-plane.
 */
class yz_rect : public hittable {
  public: 
  yz_rect() {}

   /**
     * @brief Constructs an xy_rect with specified parameters.
     * @param _y0 Minimum y-coordinate.
     * @param _y1 Maximum y-coordinate.
     * @param _z0 Minimum z-coordinate.
     * @param _z1 Maximum z-coordinate.
     * @param _k x-coordinate of the rectangle.
     * @param mat Material of the rectangle.
     */
  yz_rect(double _y0, double _y1, double _z0, double _z1, double _k,
    shared_ptr<material> mat);
    
  /**
   * @brief Determines if a ray hits the rectangle.
   * 
   *
   * @param r The ray.
   * @param ray_t The valid interval for the ray parameter.
   * @param rec The hit record to be filled if the ray hits the object.
   * @return True if the ray hits the object, false otherwise.
   */
  virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const override;
  private: 
    shared_ptr<material> mp;
    double y0, y1, z0, z1, k; 
};
