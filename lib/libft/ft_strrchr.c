/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:12:21 by noavetis          #+#    #+#             */
/*   Updated: 2025/01/26 16:36:11 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr1;
	char	*ptr2;

	ptr1 = (char *)s;
	ptr2 = NULL;
	while (*ptr1)
	{
		if (*ptr1 == (unsigned char)c)
			ptr2 = ptr1;
		ptr1++;
	}
	if ((unsigned char)c == '\0')
		return (ptr1);
	return (ptr2);
}
