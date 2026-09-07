#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "vector.h"
#include "sphere.h"

// Function to render the scene
void render_scene(Color *pixels, int width, int height, Sphere *spheres, int sphere_count, Vector light_position, int use_diffuse_lighting);

// Function to calculate the color of a pixel based on ray-sphere intersection
Color calculate_color(Vector ray_origin, Vector ray_direction, Sphere *spheres, int sphere_count, Vector light_position, int use_diffuse_lighting);

// Function to handle diffuse lighting calculations
Color calculate_diffuse_lighting(Vector normal, Vector light_direction, Color sphere_color);

#endif // RAYTRACER_H