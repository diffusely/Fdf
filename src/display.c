/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 22:15:51 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/08 00:10:14 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw()
{
	
}

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

int	key_hook(int keycode, void *param)
{
	t_view *v = (t_view *)param;
	t_map	*m = v->map;
	
	(void)param;
	if (keycode == ESC_KEY)
	{
		mlx_loop_end(v->mlx);
		mlx_destroy_window(v->mlx, v->win);
		free_matrix(m);
		free(v->mlx);
		exit(0);
	}
	return (0);
}

void	init_window(t_map *m, t_view *v)
{
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, WIDTH, HEIGHT, "Fdf");
	v->img = mlx_new_image(v->mlx, WIDTH, HEIGHT);
	v->addr = mlx_get_data_addr(v->img, &v->bpp, &v->ll, &v->endian);
	v->map = m;

	draw_map(m, v);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	
	mlx_key_hook(v->win, key_hook, v);
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

	i = 0;
	int offset_x = WIDTH / 2;
	int offset_y = HEIGHT / 2;

	while (i < m->height)
	{
		j = 0;
		while (j < m->width)
		{
			int z = m->matrix[i][j] * 8;
			st.x = iso_x(j * 20, i * 20) + offset_x;
			st.y = iso_y(j * 20, i * 20, z) + offset_y;
			if (j < m->width - 1)
			{
				int z_right = m->matrix[i][j + 1] * 8;
				end.x = iso_x((j + 1) * 20, i * 20) + offset_x;
				end.y = iso_y((j + 1) * 20, i * 20, z_right) + offset_y;
				v->color = get_color((z + z_right) / 2);
				draw_line(st, end, v);
			}
			if (i < m->height - 1)
			{
				int z_down = m->matrix[i + 1][j] * 8;
				end.x = iso_x(j * 20, (i + 1) * 20) + offset_x;
				end.y = iso_y(j * 20, (i + 1) * 20, z_down) + offset_y;
				v->color = get_color((z + z_down) / 2);
				draw_line(st, end, v);
			}
			j++;
		}
		i++;
	}

}
