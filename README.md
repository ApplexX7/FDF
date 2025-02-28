# FDF - 42 Wireframe Viewer

<img width="1228" alt="Screen Shot 2024-09-07 at 11 03 18 AM" src="https://github.com/user-attachments/assets/ec1ac924-2c5f-4af9-8002-57f49e06f57f">

A simple 3D wireframe renderer for 42 School. Renders topographic maps from `.fdf` files using Bresenham's line algorithm and custom graphics library (MinilibX).

## Features

- 🗺 Parse `.fdf` map files with elevation and color data
- 🎨 Height-based color gradients and custom colors
- 🕹 Interactive controls:
  - Rotation (X/Y/Z axes)
  - Zoom in/out
  - Translation
  - Projection toggle (Isometric/Parallel)
  - Height exaggeration
- 📊 Heads-up display with project information
- 🖥 Cross-platform support (Linux/macOS)

## Installation

### Native Build
```bash
git clone --recurse-submodules https://github.com/ApplexX7/FDF.git
cd FDF
make all          # Build project
./FDF maps/42.fdf # Run with sample map
```
## Docker Build
```
make run-docker  # Builds and runs in container automatically
```
## Controls
```
Key	Action
WASD	Move map
Q/E	Z-axis rotation
Arrow Keys	X/Y-axis rotation
+/-	Zoom in/out
I/P	Toggle projection mode
C	Cycle color modes
R	Reset view
↑/↓	Adjust vertical scaling
ESC	Quit program
```
## Project Structure

FDF/
├── includes/       - Header files
├── src/            - Source code
│   ├── parsing/    - Map parsing logic
│   ├── rendering/  - Graphics operations
│   └── utils/      - Helper functions
├── maps/           - Sample maps
└── minilibx-linux/ - Graphics library



https://github.com/user-attachments/assets/716994b2-ed7f-4547-82b6-b367a115a93a

https://github.com/user-attachments/assets/22c07754-cb19-4a8f-9d41-97a653156eca

