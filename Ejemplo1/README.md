# Ray Tracer SDL

## Overview
This project is a basic ray tracer implemented in C using the SDL library. It generates real-time images by rendering spheres with diffuse lighting based on their implicit equations. The project is designed to demonstrate fundamental ray tracing concepts and provide a foundation for further development.

## Project Structure
```
raytracer-sdl
├── src
│   ├── main.c          # Entry point of the application
│   ├── vector.h        # Header file for vector operations
│   ├── vector.c        # Implementation of vector operations
│   ├── sphere.h        # Header file for sphere operations
│   ├── sphere.c        # Implementation of sphere operations
│   ├── raytracer.h     # Header file for ray tracing functions
│   └── raytracer.c     # Implementation of ray tracing logic
├── Makefile            # Build instructions for the project
└── README.md           # Documentation for the project
```

## Setup Instructions
1. **Install SDL2**: Ensure that you have the SDL2 library installed on your system. You can download it from the [SDL website](https://www.libsdl.org/download-2.0.php) or install it using your package manager.

2. **Clone the Repository**: Clone this repository to your local machine using:
   ```
   git clone <repository-url>
   ```

3. **Build the Project**: Navigate to the project directory and run the following command to build the project:
   ```
   make
   ```

4. **Run the Application**: After building, you can run the application with:
   ```
   ./raytracer-sdl
   ```

## Usage
Once the application is running, it will display a window rendering the scene with hardcoded spheres. The spheres are rendered with diffuse lighting, allowing you to see the effects of light on their surfaces.

## Ray Tracing Algorithm
The ray tracing algorithm implemented in this project follows these basic steps:
1. **Ray Generation**: For each pixel on the screen, a ray is generated from the camera position through the pixel.
2. **Intersection Testing**: The ray is tested for intersections with the spheres defined in the scene.
3. **Lighting Calculation**: If an intersection occurs, the color of the pixel is calculated based on the diffuse lighting model.
4. **Rendering**: The calculated colors are rendered to the screen in real-time.

## Future Improvements
This project serves as a starting point for more advanced features, such as:
- Adding support for more complex shapes.
- Implementing reflections and refractions.
- Enhancing lighting models (e.g., specular lighting).
- Adding textures to the spheres.

Feel free to contribute to the project or use it as a basis for your own ray tracing experiments!