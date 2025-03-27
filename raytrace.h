#ifndef RAYTRACE_H
#define RAYTRACE_H

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <memory>
#include <sstream>

using std::make_shared;
using std::shared_ptr;

const float infinity = std::numeric_limits<float>::infinity();
const float pi = 3.1415926535897932385;

inline float deg_to_rad(float degrees) {
    return degrees * pi / 180.0;
}

inline double random_double() {
    // Returns a random real in [0,1).
    return std::rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max) {
    // Returns a random real in [min,max).
    return min + (max-min)*random_double();
}

#include "interval.h"
#include "color.h"
#include "hittable.h"
#include "hittable_list.h"
#include "ray.h"
#include "sphere.h"
#include "vec3.h"
#include "cimage.h"
#include "material.h"

#endif