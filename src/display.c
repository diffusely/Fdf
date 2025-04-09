/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 22:15:51 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/10 01:16:59 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print(t_map m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m.height)
	{
		j = 0;
		while (j < m.width)
		{
			printf("%d ", m.mt[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

static void	map_helper(int i, int j, t_view *v)
{
	t_coord	st;
	t_coord	end;
	float	s;

	s = 10 * v->zoom;
	st.z = v->map->mt[i][j];
	st.x = iso_x(j * s, i * s) + v->map->point.x + WIDTH / 2;
	st.y = iso_y(j * s, i * s, st.z) + v->map->point.y + HEIGHT / 2;
	if (j < v->map->width - 1)
	{
		end.x = iso_x((j + 1) * s, i * s) + v->map->point.x + WIDTH / 2;
		end.y = iso_y((j + 1) * s, i * s,
				v->map->mt[i][j + 1]) + v->map->point.y + HEIGHT / 2;
		v->color = get_color((st.z + v->map->mt[i][j + 1]));
		draw_line(st, end, v);
	}
	if (i < v->map->height - 1)
	{
		end.x = iso_x(j * s, (i + 1) * s) + v->map->point.x + WIDTH / 2;
		end.y = iso_y(j * s, (i + 1) * s,
				v->map->mt[i + 1][j]) + v->map->point.y + HEIGHT / 2;
		v->color = get_color((st.z + v->map->mt[i + 1][j]));
		draw_line(st, end, v);
	}
}

void	draw_map(t_view *v)
{
	int		i;
	int		j;

	i = 0;
	while (i < v->map->height)
	{
		j = 0;
		while (j < v->map->width)
		{
			map_helper(i, j, v);
			j++;
		}
		i++;
	}
}
