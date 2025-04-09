/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:56:08 by noavetis          #+#    #+#             */
/*   Updated: 2025/01/13 21:01:51 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*ptr;
	int		size;
	int		i;

	i = 0;
	size = 0;
	while (src[size])
		size++;
	ptr = (char *)malloc(size + 1);
	if (!ptr)
		return (0);
	while (i < size + 1)
	{
		ptr[i] = src[i];
		i++;
	}
	return (ptr);
}
