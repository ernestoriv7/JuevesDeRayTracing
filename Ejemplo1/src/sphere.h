#ifndef SPHERE_H
#define SPHERE_H

#include "vector.h"

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Color;

typedef struct {
    Vector center;
    float radius;
    Color color;
} Sphere;

int intersect_ray_sphere(Vector origin, Vector direction, Sphere sphere, float *t);
Vector get_sphere_normal(Sphere sphere, Vector point);

#endif // SPHERE_H