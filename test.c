#include "includes/mlx.h"
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    void *mlx;
    void *win;
} t_data;

void draw_pixel(t_data *data, int x, int y, int color) {
    mlx_pixel_put(data->mlx, data->win, x, y, color);
}

int main() {
    t_data data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "FDF");

    // Example: Draw a simple grid
    for (int x = 100; x < 400; x += 10)
        for (int y = 100; y < 400; y += 10)
            draw_pixel(&data, x, y, 0xFFFFFF);

    mlx_loop(data.mlx);
    return 0;
}
