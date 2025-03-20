/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:15:43 by noavetis          #+#    #+#             */
/*   Updated: 2025/03/18 16:00:28 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, const char *s2, size_t size, int join)
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

size_t	ft_strlen(const char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i])
		i++;
	return (i);
}

size_t	check_n(const char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}
