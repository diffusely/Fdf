/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:00:27 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/12 16:50:51 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	interpolate_color(int c1, int c2, float t)
{
	int	r;
	int	g;
	int	b;

	r = ((c1 >> 16) & 0xFF) + t * (((c2 >> 16) & 0xFF) - ((c1 >> 16) & 0xFF));
	g = ((c1 >> 8) & 0xFF) + t * (((c2 >> 8) & 0xFF) - ((c1 >> 8) & 0xFF));
	b = (c1 & 0xFF) + t * ((c2 & 0xFF) - (c1 & 0xFF));
	return ((r << 16) | (g << 8) | b);
}

void	fill_background(t_view *v, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_pixel_put(v, x, y, color);
			x++;
		}
		y++;
	}
}
