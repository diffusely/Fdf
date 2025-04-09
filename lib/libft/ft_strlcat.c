/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:10:14 by noavetis          #+#    #+#             */
/*   Updated: 2025/01/26 22:07:43 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	size_dest;
	size_t	size_src;

	size_dest = 0;
	size_src = 0;
	i = 0;
	while (dst[size_dest] != '\0')
		size_dest++;
	while (src[size_src] != '\0')
		size_src++;
	if (dstsize <= size_dest)
		return (dstsize + size_src);
	while (src[i] != '\0' && size_dest + i < dstsize - 1)
	{
		dst[size_dest + i] = src[i];
		i++;
	}
	dst[size_dest + i] = '\0';
	return (size_dest + size_src);
}
