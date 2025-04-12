/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:59:49 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/12 19:51:01 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	iso_x(int x, int y, int flag)
{
	if (flag)
		return ((x - y) * cos(ANGLE));
	return (x);
}

int	iso_y(int x, int y, int z, int flag)
{
	if (flag)
		return ((x + y) * sin(ANGLE) - z);
	return (y);
}

static void	rotation_x(float *x, float *y, float angle)
{
	float	dx;
	float	dy;

	dx = *x;
	dy = *y;
	*x = dx * cos(angle) - dy * sin(angle);
	*y = dx * sin(angle) + dy * cos(angle);
}

static void	rotation_y(float *x, float *z, float angle)
{
	float	dx;
	float	dz;

	dx = *x;
	dz = *z;
	*x = dx * cos(angle) + dz * sin(angle);
	*z = -dx * sin(angle) + dz * cos(angle);
}

void	rotation(float *x, float *y, float *z, t_view *v)
{
	if (v->flag == 0)
		rotation_x(x, y, v->rot);
	else if (v->flag == 1)
		rotation_y(x, z, v->rot);
	else if (v->flag == 2)
	{
		rotation_x(x, y, v->rot);
		rotation_y(x, z, v->rot);
	}
}
