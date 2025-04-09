/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:00:27 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/09 21:01:06 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(int z)
{
	if (z > 50)
		return (0xFF0000);
	else if (z > 20)
		return (0xFFA500);
	else if (z > 0)
		return (0xFFFF00);
	else if (z == 0)
		return (0x00FFFF);
	else if (z > -20)
		return (0xFFFFFF);
	else
		return (0x0000FF);
}
