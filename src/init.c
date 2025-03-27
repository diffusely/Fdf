/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:30:01 by noavetis          #+#    #+#             */
/*   Updated: 2025/03/27 21:11:00 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static void	matrix_helper()
// {
	
// }

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

// int	**init_matrix(t_view v, char *line, int fd)
// {
// 	char	**num;
// 	char	*ptr;
// 	char	*res;

// 	(void)v;
// 	num = ft_split(line, ' ');
	
// 	res = get_next_line(fd);
// 	ptr = res;
// 	while (ptr)
// 	{
// 		ptr = get_next_line(fd);
// 		if (!ptr)
// 			break ;
// 		res = ft_strjoin(res, ptr);
// 	}
// 	//ft_putstr_fd(res, 1);
// 	return (num);
// }
