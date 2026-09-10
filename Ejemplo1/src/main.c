#include <stdio.h>
#include <stdlib.h>
#include "raytracer.h"

#define WIDTH 1000
#define HEIGHT 1000
#define USE_DIFFUSE_LIGHTING 1 // set to 0 to show flat sphere colors
#define SPHERE_RADIUS 1.0f          
Vector light_position = {0, 0, 0}; // move this to light the spheres from a different angle

int main(void) {
    Sphere spheres[] = {
        {{0, 0, -5}, 1.0f, {255, 0, 0}},   // red sphere, radius 1
        {{2, 0, -5}, 0.5f, {0, 0, 255}}, // blue sphere, radius 0.5
        {{-2, 0, -5}, 0.5f, {0, 255, 0}}, // green sphere, radius 0.5
    };
    int sphere_count = sizeof(spheres) / sizeof(spheres[0]);
   

    Color *pixels = malloc(WIDTH * HEIGHT * sizeof(Color));
    if (!pixels) {
        fprintf(stderr, "Could not allocate pixel buffer\n");
        return 1;
    }

    render_scene(pixels, 
                 WIDTH, 
                 HEIGHT, 
                 spheres, 
                 sphere_count, 
                 light_position, 
                 USE_DIFFUSE_LIGHTING);

    FILE *out = fopen("output.ppm", "wb");
    if (!out) {
        fprintf(stderr, "Could not open output.ppm for writing\n");
        free(pixels);
        return 1;
    }

    fprintf(out, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(pixels, sizeof(Color), (size_t)WIDTH * HEIGHT, out);

    fclose(out);
    free(pixels);

    return 0;
}