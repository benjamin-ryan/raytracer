#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>

using color = vec3;

void color_out(std::ostream& out, const color& pixel_color) {
    static const interval intensity(0.000, 0.999);
    int red_byte   = int(256 * intensity.clamp(pixel_color.x()));
    int green_byte = int(256 * intensity.clamp(pixel_color.y()));
    int blue_byte  = int(256 * intensity.clamp(pixel_color.z()));

    out << red_byte << ' ' << green_byte << ' ' << blue_byte << '\n';
}

#endif