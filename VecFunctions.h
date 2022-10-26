#pragma once
#include <math.h>
#include "Vec2.h"
#include "Vec3.h"

float clamp(float value, float min, float max){
    return fmax(fmin(value, max), min);
}

float length(vec2 const& vec){
    return sqrt(vec.x * vec.x + vec.y * vec.y);
}
float length(vec3 const& vec){
    return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

vec3 norm(vec3 vec){
    return vec / length(vec);
}
float dot(vec3 const& vec_1, vec3 const& vec_2){
    return vec_1.x * vec_2.x + vec_1.y * vec_2.y + vec_1.z * vec_2.z;
}
vec3 abs(vec3 const& vec){
    return vec3(abs(vec.x), abs(vec.y), abs(vec.z));
}
vec2 sphere(vec3 ro, vec3 rd, float r) {
    float b = dot(ro, rd);
    float c = dot(ro, ro) - r * r;
    float h = b * b - c;
    if (h < 0.0) return vec2(-1.0);
    h = sqrt(h);
    return vec2(-b - h, -b + h);
}