/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:09:37 by noavetis          #+#    #+#             */
/*   Updated: 2025/03/25 23:23:32 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdlib.h>

#include <mlx.h>
#include <math.h>


#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define PI 3.14159265358979323846

typedef struct {
    void *mlx;
    void *win;
    double angle; // Rotation angle
} Clock;

// Function to draw a pixel (simple alternative)
void put_pixel(void *mlx, void *win, int x, int y, int color) {
    mlx_pixel_put(mlx, win, x, y, color);
}

void draw_clock_face(void *mlx, void *win) {
    for (int i = 0; i < 360; i += 30) {
        double rad = i * (PI / 180);
        int x0 = WIDTH / 2 + cos(rad) * 90;
        int y0 = HEIGHT / 2 + sin(rad) * 90;
        put_pixel(mlx, win, x0, y0, 0xFFFFFF);
    }
}


int update_clock(void *param) {
    Clock *clock = (Clock *)param;
    mlx_clear_window(clock->mlx, clock->win);

    draw_clock_face(clock->mlx, clock->win);

    double rad = clock->angle * (PI / 180);
    int x_end = WIDTH / 2 + cos(rad) * 80;
    int y_end = HEIGHT / 2 + sin(rad) * 80;
	t_coord start, end;
	start.x = WIDTH / 2;
	start.y = HEIGHT / 2;
	end.x = x_end;
	end.y = y_end;

	t_view v;
	v.mlx = clock->mlx;
	v.win = clock->win;
    draw_line(start, end, v);
	usleep(25000); 
    clock->angle += 2;
    if (clock->angle >= 360) clock->angle = 0;

    return 0;
}

// Handle key events to close the window
int key_hook(int keycode, void *param) {
    if (keycode == 65307) { // ESC key
        Clock *clock = (Clock *)param;
        mlx_destroy_window(clock->mlx, clock->win);
        exit(0);
    }
    return 0;
}

// Main function
int main() {
    Clock clock;
    clock.mlx = mlx_init();
    clock.win = mlx_new_window(clock.mlx, WIDTH, HEIGHT, "Rotating Clock");
    clock.angle = 0;

    mlx_loop_hook(clock.mlx, update_clock, &clock);
    mlx_key_hook(clock.win, key_hook, &clock);
    mlx_loop(clock.mlx);
    
    return 0;
}



