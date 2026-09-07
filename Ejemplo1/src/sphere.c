#include "sphere.h"
#include <math.h>

int intersect_ray_sphere(Vector origin, Vector direction, Sphere sphere, float *t) {
    Vector oc = vector_sub(origin, sphere.center);
    float a = vector_dot(direction, direction);
    float b = 2.0f * vector_dot(oc, direction);
    float c = vector_dot(oc, oc) - sphere.radius * sphere.radius;
    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return 0; // No intersection
    } else {
        *t = (-b - sqrtf(discriminant)) / (2.0f * a);
        return 1; // Intersection occurred
    }
}

Vector get_sphere_normal(Sphere sphere, Vector point) {
    Vector normal = vector_sub(point, sphere.center);
    return vector_normalize(normal);
}