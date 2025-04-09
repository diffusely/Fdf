/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:03:45 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/10 01:48:55 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_view *v)
{
	if (keycode == ESC_KEY)
		free_all(v);
	else if (keycode == A)
		v->map->point.x -= 10;
	else if (keycode == S)
		v->map->point.y += 10;
	else if (keycode == D)
		v->map->point.x += 10;
	else if (keycode == W)
		v->map->point.y -= 10;
	new_img(v);
	return (0);
}

void	free_all(t_view *v)
{
	mlx_destroy_image(v->mlx, v->img);
	mlx_destroy_window(v->mlx, v->win);
	mlx_destroy_display(v->mlx);
	free_matrix(v->map);
	free(v->map);
	free(v->mlx);
	free(v);
	exit(0);
}

int	close_window(void *param)
{
	t_view	*v;

	v = (t_view *)param;
	free_all(v);
	return (0);
}

void	new_img(t_view	*v)
{
	mlx_destroy_image(v->mlx, v->img);
	v->img = mlx_new_image(v->mlx, WIDTH, HEIGHT);
	v->addr = mlx_get_data_addr(v->img, &v->bpp, &v->ll, &v->endian);
	draw_map(v);
	mlx_put_image_to_window(v->mlx, v->win,
		v->img, 0, 0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_view	*v;

	(void)x;
	(void)y;
	v = (t_view *)param;
	if (button == ZOOM_IN_KEY)
	{
		v->zoom *= 1.1f;
		if (v->zoom > 2.0f)
			v->zoom = 2.0f;
		new_img(v);
	}
	else if (button == ZOOM_OUT_KEY)
	{
		v->zoom *= 0.9;
		if (v->zoom < 0.05f)
			v->zoom = 0.05f;
		new_img(v);
	}
	return (0);
}
