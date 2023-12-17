#include "rect.hpp"

xy_rect::xy_rect(double _x0, double _x1, double _y0, double _y1, double _k, 
  shared_ptr<material> mat)
  : x0(_x0), x1(_x1), y0(_y0), y1(_y1), k(_k), mp(mat) {};


bool xy_rect::hit(const ray& r, interval ray_t, hit_record& rec) const {
      auto t = (k-r.origin().z()) / r.direction().z();
      if (t < ray_t.min || t > ray_t.max) {
        return false; 
      }
      auto x = r.origin().x() + t*r.direction().x(); 
      auto y = r.origin().y() + t*r.direction().y(); 
      if (x < x0 || x > x1 || y < y0 || y > y1) {
        return false; 
      }
      rec.t = t; 
      auto outward_normal = vec3(0,0,1); 
      rec.set_face_normal(r, outward_normal); 
      rec.mat_ptr = mp; 
      rec.p = r.at(t); 
      return true; 
}


xz_rect::xz_rect(double _x0, double _x1, double _z0, double _z1, double _k, 
  shared_ptr<material> mat)
  : x0(_x0), x1(_x1), z0(_z0), z1(_z1), k(_k), mp(mat) {};


bool xz_rect::hit(const ray& r, interval ray_t, hit_record& rec) const {
      auto t = (k-r.origin().y()) / r.direction().y();
      if (t < ray_t.min || t > ray_t.max) {
        return false; 
      }
      auto x = r.origin().x() + t*r.direction().x(); 
      auto z = r.origin().z() + t*r.direction().z(); 
      if (x < x0 || x > x1 || z < z0 || z > z1) {
        return false; 
      }
      rec.t = t; 
      auto outward_normal = vec3(0,0,1); 
      rec.set_face_normal(r, outward_normal); 
      rec.mat_ptr = mp; 
      rec.p = r.at(t); 
      return true; 
}


yz_rect::yz_rect(double _y0, double _y1, double _z0, double _z1, double _k,
  shared_ptr<material> mat)
  : y0(_y0), y1(_y1), z0(_z0), z1(_z1), k(_k), mp(mat) {};

bool yz_rect::hit(const ray& r, interval ray_t, hit_record& rec) const {
    auto t = (k-r.origin().x()) / r.direction().x();
      if (t < ray_t.min || t > ray_t.max) {
        return false; 
      }
      auto y = r.origin().y() + t*r.direction().y(); 
      auto z = r.origin().z() + t*r.direction().z(); 
      if (y < y0 || y > y1 || z < z0 || z > z1) {
        return false; 
      } 
      rec.t = t; 
      auto outward_normal = vec3(0,0,1); 
      rec.set_face_normal(r, outward_normal); 
      rec.mat_ptr = mp; 
      rec.p = r.at(t); 
      return true; 
}