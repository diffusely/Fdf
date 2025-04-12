# FDF - Wireframe 3D Renderer

## 🗺️ Overview

**FDF** is a simple 3D wireframe viewer written in C, built using the **MiniLibX** graphics library. It takes a file containing a 2D grid of height values and renders a 3D isometric projection of the terrain.

This project was developed as part of the 42 school curriculum.

---

## 📦 Features

- 3D isometric projection of a heightmap
- Rotation on X, Y, and Z axes
- Zoom and movement controls
- Color gradients based on height
- Smooth line drawing (Bresenham’s algorithm)
- Custom projection matrix and transformations
- Lightweight, using only MiniLibX (no external engines)

---

## 🧠 Concepts

- Basic graphics programming with MiniLibX
- 3D to 2D projection
- Rotation matrices
- Line drawing algorithms
- File parsing and memory management

---

## 🕹️ Controls

| Key           | Action                      |
|---------------|-----------------------------|
| `W` / `S`     | Move map up / down          |
| `A` / `D`     | Move map left / right       |
| Arrow Keys    | Optional: fine movement     |
| `R`           | Rotate                      |
| `E`           | Change rotation mode (X/Y/Z)|
| `T`           | Switch to top-down view     |
| `+` / `-`     | Increase / Decrease Z-scale |
| `ESC`         | Exit program                |

---

## 🔧 Build Instructions

```bash
git clone https://github.com/diffusely/Fdf.git
cd fdf
make
./fdf maps/42.fdf

![image alt](https://github.com/diffusely/Fdf/blob/main/Screenshot%20from%202025-04-12%2021-00-38.png?raw=true)




![Image](https://github.com/user-attachments/ahttps://github.com/diffusely/Fdf/blob/main/Screenshot%20from%202025-04-12%2021-00-38.png?raw=truessets/7d547e98-6050-4673-bffe-ef37401b2f57)
