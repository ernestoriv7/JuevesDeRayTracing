#include <math.h>
#include <stddef.h>
#include "raytracer.h"
#include "sphere.h"
#include "vector.h"

Vector ray_origin = {0, 0, 0};

Color calculate_diffuse_lighting(Vector normal, Vector light_direction, Color sphere_color) {
    float brightness = fmaxf(vector_dot(normal, light_direction), 0.0f);
    Color result;
    result.r = (unsigned char)(sphere_color.r * brightness);
    result.g = (unsigned char)(sphere_color.g * brightness);
    result.b = (unsigned char)(sphere_color.b * brightness);
    return result;
}

Color calculate_color(Vector ray_origin, 
                      Vector ray_direction, 
                      Sphere *spheres, 
                      int sphere_count, 
                      Vector light_position, 
                      int use_diffuse_lighting) {
    Color background = {0, 0, 0};

    float closest_t = INFINITY;
    Sphere *closest_sphere = NULL;

    for (int i = 0; i < sphere_count; i++) {
        float t;
        if (intersect_ray_sphere(ray_origin, ray_direction, spheres[i], &t) && t > 0 && t < closest_t) {
            closest_t = t;
            closest_sphere = &spheres[i];
        }
    }

    if (!closest_sphere) {
        return background;
    }

    if (!use_diffuse_lighting) {
        return closest_sphere->color;
    }

    Vector hit_point = vector_add(ray_origin, vector_scale(ray_direction, closest_t));
    Vector normal = get_sphere_normal(*closest_sphere, hit_point);
    Vector light_dir = vector_normalize(vector_sub(light_position, hit_point));
    return calculate_diffuse_lighting(normal, light_dir, closest_sphere->color);
}

void render_scene(Color *pixels, 
                  int width, 
                  int height, 
                  Sphere *spheres, 
                  int sphere_count, 
                  Vector light_position, 
                  int use_diffuse_lighting) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Vector ray_origin = {0, 0, 0};
            Vector ray_dir = {(float)x / width - 0.5f, (float)y / height - 0.5f, -1};
            ray_dir = vector_normalize(ray_dir);

            pixels[y * width + x] = calculate_color(ray_origin, 
                                                    ray_dir, 
                                                    spheres, 
                                                    sphere_count, 
                                                    light_position, 
                                                    use_diffuse_lighting);
        }
    }
}