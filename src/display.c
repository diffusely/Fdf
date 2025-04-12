/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 22:15:51 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/12 19:52:13 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_color(t_coord *st, t_coord *end, int flag)
{
	if (st->z > end->z)
	{
		st->color = st->s_color;
		end->color = st->e_color;
		if (flag)
			ft_swap(&st->color, &end->color);
	}
	else if (st->z < end->z)
	{
		st->color = st->e_color;
		end->color = st->s_color;
		if (flag)
			ft_swap(&st->color, &end->color);
	}
	else if (st->z == end->z && end->z > 0)
	{
		st->color = st->s_color;
		end->color = st->s_color;
	}
	else
	{
		st->color = st->e_color;
		end->color = st->e_color;
	}
}

static void	init_point(int i, int j, t_coord *st, t_view *v)
{
	float	x;
	float	y;
	float	s;
	float	z;

	s = v->zoom * SIZE;
	x = j * s;
	y = i * s;
	z = v->map->mt[i][j];
	st->z = v->map->mt[i][j];
	rotation(&x, &y, &z, v);
	st->x = iso_x(x, y, v->t_flag) + v->map->point.x + WIDTH / 2;
	st->y = iso_y(x, y, z, v->t_flag) + v->map->point.y + HEIGHT / 2;
}

static void	draw_horizontal(t_coord st, t_coord end, t_coord dir, t_view *v)
{
	float	x;
	float	y;
	float	s;
	float	z;

	s = v->zoom * SIZE;
	if (dir.y < v->map->width - 1)
	{
		x = (dir.y + 1) * s;
		y = dir.x * s;
		end.z = v->map->mt[dir.x][dir.y + 1];
		z = v->map->mt[dir.x][dir.y + 1];
		init_color(&st, &end, 0);
		rotation(&x, &y, &z, v);
		end.x = iso_x(x, y, v->t_flag) + v->map->point.x + WIDTH / 2;
		end.y = iso_y(x, y, z, v->t_flag) + v->map->point.y + HEIGHT / 2;
		draw_line(st, end, v);
	}
}

static void	draw_vertical(t_coord st, t_coord end, t_coord dir, t_view *v)
{
	float	x;
	float	y;
	float	s;
	float	z;

	s = v->zoom * SIZE;
	if (dir.x < v->map->height - 1)
	{
		x = dir.y * s;
		y = (dir.x + 1) * s;
		z = v->map->mt[dir.x + 1][dir.y];
		end.z = v->map->mt[dir.x + 1][dir.y];
		init_color(&st, &end, 1);
		rotation(&x, &y, &z, v);
		end.x = iso_x(x, y, v->t_flag) + v->map->point.x + WIDTH / 2;
		end.y = iso_y(x, y, z, v->t_flag) + v->map->point.y + HEIGHT / 2;
		draw_line(st, end, v);
	}
}

void	draw_map(t_view *v, int c1, int c2)
{
	t_coord	st;
	t_coord	end;
	t_coord	dir;

	st.s_color = c1;
	st.e_color = c2;
	dir.x = 0;
	while (dir.x < v->map->height)
	{
		dir.y = 0;
		while (dir.y < v->map->width)
		{
			init_point(dir.x, dir.y, &st, v);
			draw_horizontal(st, end, dir, v);
			draw_vertical(st, end, dir, v);
			++dir.y;
		}
		++dir.x;
	}
}
