#pragma once

struct vec3{
    float x, y, z;

    vec3(float value) : x(value), y(value), z(value) {}
    vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    vec3(float _x, vec2 const& vec) : x(_x), y(vec.x), z(vec.y){}

    vec3 operator+(vec3 const& other){
        return vec3(x + other.x, y + other.y, z + other.z);
    }
    vec3 operator-(vec3 const& other){
        return vec3(x - other.x, y - other.y, z - other.z);
    }
    vec3 operator*(vec3 const& other){
        return vec3(x * other.x, y * other.y, z * other.z);
    }
    vec3 operator/(vec3 const& other){
        return vec3(x / other.x, y / other.y, z / other.z);
    }
    vec3 operator-(){
        return vec3(-x, -y, -z);
    }
};