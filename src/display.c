/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 22:15:51 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/07 22:52:46 by noavetis         ###   ########.fr       */
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

void	exit_f()
{
	printf("a");
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
	v->map = m;

	
	draw_map(m, v);
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

void	draw_map(t_map *m, t_view *v)
{
	t_coord	st;
	t_coord	end;
	
	int	i;
	int	j;

	i = 0;
	int offset_x = WIDTH / 2 - (m->width * 20) / 2;
	int offset_y = HEIGHT / 2 - (m->height * 20) / 2;

	while (i < m->height)
	{
		j = 0;
		while (j < m->width)
		{
			int z = m->matrix[i][j] * 10;
			st.x = iso_x(j * 20, i * 20) + offset_x;
			st.y = iso_y(j * 20, i * 20, z) + offset_y;
			if (j < m->width - 1)
			{
				int z_right = m->matrix[i][j + 1] * 10;
				end.x = iso_x((j + 1) * 20, i * 20) + offset_x;
				end.y = iso_y((j + 1) * 20, i * 20, z_right) + offset_y;
				draw_line(st, end, *v);
			}
			if (i < m->height - 1)
			{
				int z_down = m->matrix[i + 1][j] * 10;
				end.x = iso_x(j * 20, (i + 1) * 20) + offset_x;
				end.y = iso_y(j * 20, (i + 1) * 20, z_down) + offset_y;
				draw_line(st, end, *v);
			}
			j++;
		}
		i++;
	}

}
