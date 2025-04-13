/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:55:10 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/13 18:44:41 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_width(const char *file_name)
{
	int		width;
	int		temp;
	char	*ptr;
	int		fd;

	fd = open_file(file_name);
	ptr = get_next_line(fd);
	width = word_count_sep(ptr, " \n");
	temp = width;
	while (ptr)
	{
		free(ptr);
		ptr = get_next_line(fd);
		if (temp == width)
		{
			if (!ptr)
				break ;
			width = word_count_sep(ptr, " \n");
		}
	}
	if (temp != width)
		return (fd_close(fd), free(ptr), -1);
	return (fd_close(fd), temp);
}

int	get_height(const char *file_name)
{
	int		height;
	char	*ptr;
	int		fd;

	height = 0;
	fd = open_file(file_name);
	ptr = get_next_line(fd);
	while (ptr)
	{
		++height;
		free(ptr);
		ptr = get_next_line(fd);
	}
	return (fd_close(fd), height);
}

void	point_up(t_view *v, int dir)
{
	int	i;
	int	j;

	i = 0;
	while (i < v->map->height)
	{
		j = 0;
		while (j < v->map->width)
		{
			if ((v->map->mt[i][j] < 1000 || dir < 0) && v->map->mt[i][j] > 0)
				v->map->mt[i][j] += dir * 10;
			j++;
		}
		i++;
	}
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
