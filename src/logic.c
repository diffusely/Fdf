/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:59:49 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/09 21:00:08 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	iso_x(int x, int y)
{
	return ((x - y) * cos(ANGLE));
}

int	iso_y(int x, int y, int z)
{
	return ((x + y) * sin(ANGLE) - z);
}
