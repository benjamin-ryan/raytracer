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

#include "interval.h"
#include "color.h"
#include "hittable.h"
#include "hittable_list.h"
#include "ray.h"
#include "sphere.h"
#include "vec3.h"
#include "cimage.h"

#endif