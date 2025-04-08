/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 22:15:51 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/08 21:04:55 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void print(t_map m)
{
	int i = 0;
	int j ;
	while (i < m.height)
	{
		j = 0;
		while (j < m.width)
		{
			printf("%d ", m.matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	init_window(t_map *m, t_view *v)
{
	v->mlx = mlx_init();
    v->win = mlx_new_window(v->mlx, WIDTH, HEIGHT, "Zoom Example");
    v->img = mlx_new_image(v->mlx, WIDTH, HEIGHT);
	v->addr = mlx_get_data_addr(v->img, &v->bpp, &v->ll, &v->endian);
    v->zoom = 1;
	v->map = m;
    // Set up mouse hook to listen for mouse events (button clicks)
	
	
    
    draw_map(m, v); // Initial map drawing
    mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);

	mlx_key_hook(v->win, key_hook, v);
	mlx_mouse_hook(v->win, mouse_hook, v);
    mlx_hook(v->win, 17, 0, close_window, v);

    // Start the mlx event loop
    mlx_loop(v->mlx);
}

int iso_x(int x, int y)
{
	return (x - y) * cos(ANGLE);
}

int iso_y(int x, int y, int z)
{
	return (x + y) * sin(ANGLE) - z;
}

int get_color(int z)
{
	if (z > 50)
		return 0xFF0000;
	else if (z > 20)
		return 0xFFA500;
	else if (z > 0)
		return 0xFFFF00;
	else if (z == 0)
		return 0x00FFFF;
	else if (z > -20)
		return 0xFFFFFF;
	else
		return 0x0000FF;
}

void	draw_map(t_map *m, t_view *v)
{
	t_coord	st;
	t_coord	end;
	
	int	i;
	int	j;
	int	size = 100 * v->zoom;
	i = 0;
	int offset_x = WIDTH / 2;
	int offset_y = HEIGHT / 2;

	if (m == NULL || m->matrix == NULL)
    {
        printf("Map is NULL\n");
        return;
    }
	while (i < m->height)
	{
		j = 0;
		while (j < m->width)
		{
			int z = m->matrix[i][j];
			st.x = iso_x(j * size, i * size) + offset_x;
			st.y = iso_y(j * size, i * size, z) + offset_y;
			if (j < m->width - 1)
			{
				int z_right = m->matrix[i][j + 1];
				end.x = iso_x((j + 1) * size, i * size) + offset_x;
				end.y = iso_y((j + 1) * size, i * size, z_right) + offset_y;
				v->color = get_color((z + z_right) / 2);
				draw_line(st, end, v);
			}
			if (i < m->height - 1)
			{
				int z_down = m->matrix[i + 1][j];
				end.x = iso_x(j * size, (i + 1) * size) + offset_x;
				end.y = iso_y(j * size, (i + 1) * size, z_down) + offset_y;
				v->color = get_color((z + z_down) / 2);
				draw_line(st, end, v);
			}
			j++;
		}
		i++;
	}
}
