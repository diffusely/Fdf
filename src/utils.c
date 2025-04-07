/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:49:03 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/07 23:37:52 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	open_file(const char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		error_handle("System error", 0);
	}
	return (fd);
}

static int	check_wcs(char *str, char c)
{
	while (str && *str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

size_t	word_count_sep(const char *str, char *s)
{
	size_t	count;

	count = 0;
	while (str && *str)
	{
		while (*str && check_wcs(s, *str))
			str++;
		if (*str)
			count++;
		while (*str && !check_wcs(s, *str))
			str++;
	}
	return (count);
}

void	ft_pixel_put(t_view *v, int x, int y, int color)
{
	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	char *dst = v->addr + (y * v->ll + x * (v->bpp / 8));
	*(unsigned int *)dst = color;
}
