/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:03:45 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/12 20:00:06 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	obj_move(int keycode, t_view *v)
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
	else if (keycode == UP)
		point_up(v, 1);
	else if (keycode == DOWN)
		point_up(v, -1);
}

int	key_hook(int keycode, t_view *v)
{
	obj_move(keycode, v);
	if (keycode == E)
	{
		++(v->flag);
		if (v->flag == 3)
			v->flag = 0;
		return (0);
	}
	else if (keycode == R)
	{
		v->rot += 0.1f;
		if (v->rot >= PI * 2)
			v->rot = 0;
	}
	else if (keycode == T)
	{
		if (v->t_flag)
			v->t_flag = 0;
		else
			v->t_flag = 1;
	}
	new_img(v);
	return (0);
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
	fill_background(v, 0x0A0E2A);
	draw_map(v, SCOLOR, ECOLOR);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
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
