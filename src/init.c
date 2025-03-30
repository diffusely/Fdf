/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:30:01 by noavetis          #+#    #+#             */
/*   Updated: 2025/03/30 22:20:27 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_matrix(t_map *m)
{
	int	i;

	i = 0;
	while (i < (*m).height)
	{
		free((*m).matrix[i]);
		i++;
	}
	free((*m).matrix);
}

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
		if (!ptr)
			break ;
		width = word_count_sep(ptr, " \n");
		if (temp != width)
			error_handle("Map width incorrect!\n", 1);
	}
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

int	*init_matrix_line(int width, int fd)
{
	char	**ptr;
	char	*r;
	int		*line;
	int		i;

	r = get_next_line(fd);
	if (!r)
		return (NULL);
	ptr = ft_split(r, ' ');
	line = (int *)malloc(width * sizeof(int));
	if (!line)
		error_handle("Bad alloc *line*!\n", 1);
	i = 0;
	while (i < width)
	{
		line[i] = ft_atoi(ptr[i]);
		i++;
	}
	while (--i >= 0)
		free(ptr[i]);
	return (free(r), free(ptr), line);
}

void	init_matrix(t_map *m, const char *file_name)
{
	int		fd;
	int		i;

	fd = open_file(file_name);
	(*m).height = get_height(file_name);
	(*m).width = get_width(file_name);
	(*m).matrix = (int **)malloc((*m).height * sizeof(int *));
	if (!(*m).matrix)
		error_handle("Bad alloc *matrix*!\n", 1);
	i = 0;
	while (i < (*m).height)
	{
		(*m).matrix[i] = init_matrix_line((*m).width, fd);
		if (!(*m).matrix[i])
		{
			while (--i > 0)
				free((*m).matrix[i]);
			free((*m).matrix);
			fd_close(fd);
			error_handle("Map is not valid!\n", 1);
		}
		i++;
	}
	fd_close(fd);
}
