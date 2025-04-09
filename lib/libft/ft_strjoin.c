/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 19:13:12 by noavetis          #+#    #+#             */
/*   Updated: 2025/01/18 19:26:25 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size;
	size_t	i;

	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (*s1)
	{
		str[i] = *(s1++);
		i++;
	}
	while (*s2)
	{
		str[i] = *(s2++);
		i++;
	}
	str[i] = '\0';
	return (str);
}
