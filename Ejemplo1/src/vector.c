#include "vector.h"
#include <math.h>

static Vector make_vector(float x, float y, float z) {
    Vector v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

Vector vector_add(Vector a, Vector b) {
    return make_vector(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vector vector_sub(Vector a, Vector b) {
    return make_vector(a.x - b.x, a.y - b.y, a.z - b.z);
}

Vector vector_scale(Vector v, float s) {
    return make_vector(v.x * s, v.y * s, v.z * s);
}

float vector_dot(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector vector_normalize(Vector v) {
    float length = sqrtf(vector_dot(v, v));
    if (length == 0) return make_vector(0, 0, 0);
    return make_vector(v.x / length, v.y / length, v.z / length);
}