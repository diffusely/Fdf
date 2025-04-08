/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:03:45 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/08 21:06:56 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, void *param)
{
	t_view	*v;

	v = (t_view *)param;
	if (keycode == ESC_KEY)
	{
		free_all(v, v->map);
	}
	return (0);
}

static void	free_all(t_view *v, t_map	*m)
{
	mlx_destroy_window(v->mlx, v->win);
	free_matrix(m);
	free(v->mlx);
	exit(0);
}

int close_window(void *param)
{
	t_view	*v;

	v = (t_view *)param;
	free_all(v, v->map);
	return (0);
}

int mouse_hook(int button, int x, int y, void *param)
{
	t_view	*v;

	(void)x;
	(void)y;
	v = (t_view *)param;
    if (button == 4)
    {
		v->zoom *= 1.1;
		if (v->zoom > 5.0f)
		v->zoom = 5.0f;

		free(v->img);
		v->img = mlx_new_image(v->mlx, WIDTH, HEIGHT);
		v->addr = mlx_get_data_addr(v->img, &v->bpp, &v->ll, &v->endian);
		draw_map(m, v);
		mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	}
	else if (button == 5)  // Scroll down
	{
		v->zoom *= 0.9;
		free(v->img);
		v->img = mlx_new_image(v->mlx, WIDTH, HEIGHT);
		v->addr = mlx_get_data_addr(v->img, &v->bpp, &v->ll, &v->endian);
		draw_map(m, v); // Initial map drawing
		mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
    }

    return (0);
}