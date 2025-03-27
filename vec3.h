#ifndef VEC3_H
#define VEC3_H

#include <iostream>

class vec3 {
public:

    float f[3];
    
    vec3() : f{0,0,0} {}
    vec3(float x, float y, float z) : f{x,y,z} {}

    float x() const { return f[0]; }
    float y() const { return f[1]; }
    float z() const { return f[2]; }

    float operator[](int i) const { return f[i]; }
    float& operator[](int i) { return f[i]; }

    vec3 operator-() const { return vec3(-f[0], -f[1], -f[2]); }

    vec3& operator+=(const vec3& v) {
        f[0] += v.f[0];
        f[1] += v.f[1];
        f[2] += v.f[2];
        return *this;
    }

    vec3& operator*=(float t) {
        f[0] *= t;
        f[1] *= t;
        f[2] *= t;
        return *this;
    }

    vec3& operator/=(float t) { return *this *= 1/t; }

    float length() const { return std::sqrt(length_squared()); }

    float length_squared() const { return f[0]*f[0] + f[1]*f[1] + f[2]*f[2]; }

    static vec3 random() {
        return vec3(random_double(), random_double(), random_double());
    }

    static vec3 random(float min, float max) {
        return vec3(random_double(min, max), random_double(min, max), random_double(min, max));
    }

};

inline double dot(const vec3& u, const vec3& v) {
    return u.f[0] * v.f[0]
         + u.f[1] * v.f[1]
         + u.f[2] * v.f[2];
}

inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(u.f[1] * v.f[2] - u.f[2] * v.f[1],
                u.f[2] * v.f[0] - u.f[0] * v.f[2],
                u.f[0] * v.f[1] - u.f[1] * v.f[0]);
}

inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.f[0] << ' ' << v.f[1] << ' ' << v.f[2];
}

inline vec3 operator+(const vec3& u, const vec3& v) {
    return vec3(u.f[0] + v.f[0], u.f[1] + v.f[1], u.f[2] + v.f[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v) {
    return vec3(u.f[0] - v.f[0], u.f[1] - v.f[1], u.f[2] - v.f[2]);
}

inline vec3 operator*(const vec3& u, const vec3& v) {
    return vec3(u.f[0] * v.f[0], u.f[1] * v.f[1], u.f[2] * v.f[2]);
}

inline vec3 operator*(double t, const vec3& v) {
    return vec3(t*v.f[0], t*v.f[1], t*v.f[2]);
}

inline vec3 operator*(const vec3& v, double t) {
    return t * v;
}

inline vec3 operator/(const vec3& v, double t) {
    return (1/t) * v;
}

inline vec3 unit_vector(const vec3& v) {
    return v / v.length();
}

inline vec3 random_unit_vector() {
    while (true) {
        auto p = vec3::random(-1,1);
        auto lensq = p.length_squared();
        if (1e-160 < lensq && lensq <= 1) // Floating point errors
            return p / sqrt(lensq);
    }
}

inline vec3 random_on_hemisphere(const vec3& normal) {
    vec3 on_unit_sphere = random_unit_vector();
    if (dot(on_unit_sphere, normal) > 0.0) // In the same hemisphere as the normal
        return on_unit_sphere;
    else
        return -on_unit_sphere;
}

#endif