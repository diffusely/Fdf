/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:12:55 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/14 16:53:53 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin_dup(char *s1, const char *s2, size_t size, int join)
{
	char	*str;
	size_t	i;

	if (join && s1)
		size += ft_strlen(s1);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (free(s1), NULL);
	i = 0;
	while (join && s1 && s1[i] && i < size)
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && *s2 && i < size)
		str[i++] = *(s2++);
	if (i == 0)
		return (free(s1), free(str), NULL);
	str[i] = '\0';
	return (free(s1), str);
}

static int	gnl_check( char **result, char **ptr)
{
	*result = NULL;
	if (*ptr)
	{
		if (check_n(*ptr))
		{
			*result = ft_strjoin_dup(NULL, *ptr, check_n(*ptr), 0);
			*ptr = ft_strjoin_dup(*ptr, *ptr + check_n(*ptr),
					ft_strlen(*ptr + check_n(*ptr)), 0);
			return (1);
		}
		*result = ft_strjoin_dup(*ptr, *ptr, ft_strlen(*ptr), 0);
		*ptr = NULL;
	}
	return (0);
}

static int	gnl_ptr_check(char **res, char **ptr,
	const char *buffer, ssize_t read_size)
{
	if (check_n(buffer))
		*res = ft_strjoin_dup(*res, buffer, check_n(buffer), 1);
	else
		*res = ft_strjoin_dup(*res, buffer, ft_strlen(buffer), 1);
	if (read_size != BUFFER_SIZE)
	{
		if (check_n(buffer))
			*ptr = ft_strjoin_dup(NULL, buffer + check_n(buffer),
					ft_strlen(buffer + check_n(buffer)), 0);
		else
			*ptr = ft_strjoin_dup(NULL, buffer + ft_strlen(buffer),
					ft_strlen(buffer + ft_strlen(buffer)), 0);
		return (1);
	}
	if (read_size == BUFFER_SIZE && check_n(buffer))
	{
		*ptr = ft_strjoin_dup(NULL, buffer + check_n(buffer),
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
		return (free(ptr), NULL);
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
