/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 19:27:08 by noavetis          #+#    #+#             */
/*   Updated: 2025/01/22 13:05:53 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	start_check(char const **s1, char const *set)
{
	size_t	j;

	while (**s1)
	{
		j = 0;
		while (set[j])
		{
			if (**s1 == set[j])
			{
				(*s1)++;
				break ;
			}
			j++;
		}
		if (set[j] == '\0')
			break ;
	}
}

static size_t	end_check(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	size;
	size_t	count;

	size = ft_strlen(s1);
	i = 0;
	count = 0;
	while (i < size)
	{
		j = 0;
		while (set[j])
		{
			if (s1[size - i - 1] == set[j])
			{
				count++;
				break ;
			}
			j++;
		}
		if (set[j] == '\0')
			break ;
		i++;
	}
	return (size - count + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	size;

	if (!s1 || !set)
		return (NULL);
	start_check(&s1, set);
	size = end_check(s1, set);
	ptr = malloc((size) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, size);
	return (ptr);
}
