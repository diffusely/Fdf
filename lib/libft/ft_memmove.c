/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:18:12 by noavetis          #+#    #+#             */
/*   Updated: 2025/01/26 20:28:55 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*str1;
	const char	*str2;
	size_t		i;

	str1 = dst;
	str2 = src;
	if (!str1 && !str2)
		return (NULL);
	i = 0;
	if (str1 > str2)
	{
		while (len-- > 0)
			str1[len] = str2[len];
	}
	else
	{
		while (i < len)
		{
			str1[i] = str2[i];
			i++;
		}
	}
	return (str1);
}
