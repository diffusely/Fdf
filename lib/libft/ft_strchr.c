/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:02:03 by noavetis          #+#    #+#             */
/*   Updated: 2025/01/26 16:33:39 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	ptr = (char *)s;
	i = 0;
	while (ptr[i])
	{
		if ((unsigned char)ptr[i] == (unsigned char)c)
			return (ptr + i);
		i++;
	}
	if ((unsigned char)c == '\0')
		return (ptr + i);
	return (NULL);
}
