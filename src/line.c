/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:48:36 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/01 19:58:13 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	swap_helper(t_coord *st, t_coord *end, int flag)
{
	if (flag && st->x < end->x)
		return ;
	if (!flag && st->y < end->y)
		return ;
	ft_swap(&st->x, &end->x);
	ft_swap(&st->y, &end->y);
}

static void	check_helper(int *dir, float *d)
{
	*dir = 1;
	if (*d < 0)
		*dir = -1;
	*d *= *dir;
}

static void	draw_line_h(t_coord st, t_coord end, t_view v)
{
	float	dx;
	float	dy;
	float	p;
	int		i;
	int		dir;

	i = -1;
	swap_helper(&st, &end, 1);
	dx = end.x - st.x;
	dy = end.y - st.y;
	check_helper(&dir, &dy);
	if (dx != 0)
	{
		p = 2 * dy - dx;
		while (++i < dx + 1)
		{
			mlx_pixel_put(v.mlx, v.win, st.x + i, st.y, 0xFFFFFF);
			if (p >= 0)
			{
				st.y += dir;
				p -= 2 * dx;
			}
			p += 2 * dy;
		}
	}
}

static void	draw_line_v(t_coord st, t_coord end, t_view v)
{
	float	dx;
	float	dy;
	float	p;
	int		i;
	int		dir;

	i = -1;
	swap_helper(&st, &end, 0);
	dx = end.x - st.x;
	dy = end.y - st.y;
	check_helper(&dir, &dx);
	if (dy != 0)
	{
		p = 2 * dx - dy;
		while (++i < dy + 1)
		{
			mlx_pixel_put(v.mlx, v.win, st.x, st.y + i, 0xFFFFFF);
			if (p >= 0)
			{
				st.x += dir;
				p -= 2 * dy;
			}
			p += 2 * dx;
		}
	}
}

void	draw_line(t_coord st, t_coord end, t_view v)
{
	if (abs(end.x - st.x) > abs(end.y - st.y))
		draw_line_h(st, end, v);
	else
		draw_line_v(st, end, v);
}
