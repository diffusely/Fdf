/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:12:55 by noavetis          #+#    #+#             */
/*   Updated: 2025/03/18 16:00:34 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	gnl_check( char **result, char **ptr)
{
	*result = NULL;
	if (*ptr)
	{
		if (check_n(*ptr))
		{
			*result = ft_strjoin(NULL, *ptr, check_n(*ptr), 0);
			*ptr = ft_strjoin(*ptr, *ptr + check_n(*ptr),
					ft_strlen(*ptr + check_n(*ptr)), 0);
			return (1);
		}
		*result = ft_strjoin(*ptr, *ptr, ft_strlen(*ptr), 0);
		*ptr = NULL;
	}
	return (0);
}

static int	gnl_ptr_check(char **res, char **ptr,
	const char *buffer, ssize_t read_size)
{
	if (check_n(buffer))
		*res = ft_strjoin(*res, buffer, check_n(buffer), 1);
	else
		*res = ft_strjoin(*res, buffer, ft_strlen(buffer), 1);
	if (read_size != BUFFER_SIZE)
	{
		if (check_n(buffer))
			*ptr = ft_strjoin(NULL, buffer + check_n(buffer),
					ft_strlen(buffer + check_n(buffer)), 0);
		else
			*ptr = ft_strjoin(NULL, buffer + ft_strlen(buffer),
					ft_strlen(buffer + ft_strlen(buffer)), 0);
		return (1);
	}
	if (read_size == BUFFER_SIZE && check_n(buffer))
	{
		*ptr = ft_strjoin(NULL, buffer + check_n(buffer),
				ft_strlen(buffer + check_n(buffer)), 0);
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char		*ptr = NULL;
	ssize_t			read_size;
	char			buffer[BUFFER_SIZE + 1];
	char			*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (gnl_check(&result, &ptr))
		return (result);
	read_size = read(fd, buffer, BUFFER_SIZE);
	if (read_size < 0)
		return (free(result), NULL);
	while (read_size > 0)
	{
		buffer[read_size] = '\0';
		if (gnl_ptr_check(&result, &ptr, buffer, read_size))
			return (result);
		read_size = read(fd, buffer, BUFFER_SIZE);
	}
	return (result);
}
