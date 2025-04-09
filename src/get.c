/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:55:10 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/09 20:59:27 by noavetis         ###   ########.fr       */
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
