/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:15:41 by noavetis          #+#    #+#             */
/*   Updated: 2025/01/17 14:06:04 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(const char *str, const char *to_find, size_t len)
{
	size_t	i;

	i = 0;
	while (to_find[i] && i < len)
	{
		if (str[i] != to_find[i])
			return (0);
		i++;
	}
	if (to_find[i] != '\0')
		return (0);
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)haystack;
	if (*needle == '\0')
		return (ptr);
	if (len == 0)
		return (NULL);
	i = 0;
	while (ptr[i] && i < len)
	{
		if (check(ptr + i, needle, len - i))
			return (ptr + i);
		i++;
	}
	return (NULL);
}
