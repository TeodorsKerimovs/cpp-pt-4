#pragma once

#include "hittable_list.hpp"
#include "vec3.hpp"

#include "ray.hpp"
#include "vec3.hpp"
#include "camera.hpp"
#include "hittable_list.hpp"
#include "sphere.hpp"
#include "material.hpp"
#include "rect.hpp"

#include "box.hpp"
#include "moving_sphere.hpp"
#include <iostream>
#include <algorithm>
#include "render.hpp"

#include <fstream>
#include <string>
#include <sstream>

class fileReadList {
    public:
        fileReadList() : cam_frompoint{0, 0, 0}, 
        cam_atpoint{0, 0, 0},
        cam_vups{0, 0, 0},
        cam_vfov{0},
        cam_aspect_ratio{0},
        cam_aperature{0},
        cam_dist_to_focus{0},
        im_w{0},
        im_h{0},
        im_spp{0},
        im_max_depth{0},
        im_bc{0, 0, 0},
        im_skylight{0},
        objs{} 
        {}
    
        void performFileRead(const std::string filename);

        point3 cam_frompoint;
        point3 cam_atpoint;
        vec3 cam_vups;
        double cam_vfov;
        double cam_aspect_ratio;
        double cam_aperature;
        double cam_dist_to_focus;

        int im_w;
        int im_h;
        int im_spp;
        int im_max_depth;
        color im_bc;
        bool im_skylight;

        hittable_list objs;    
};
