# Ray Tracer

C++ ray tracer implementation based on ["Understandable RayTracing in 256 lines of bare C++" tutorial](https://github.com/ssloy/tinyraytracer/wiki/Part-1:-understandable-raytracing).

## Features

Implemented features:

- Ray tracing itself (duh).
- Lighting.
- Specular lighting.
- Shadows.
- Reflections.
- Refractions.

## Installation

GCC compiler is required. `cppcheck` is optional.

### macOS

```bash
brew install gcc cppcheck
```

## Usage

To compile source code and render the scene described in `Source/main.cpp` run:

```
make
```
