/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:43:13 by noavetis          #+#    #+#             */
/*   Updated: 2025/01/23 19:04:00 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_size(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static void	copy(char *str, int size, int num, int n)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (num < 0 && size - i - 1 == 0)
			break ;
		str[size - i - 1] = '0' + (n % 10);
		n /= 10;
		i++;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		num;

	num = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = count_size(n);
	if (n < 0)
		size++;
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	copy(str, size, num, n);
	str[size] = '\0';
	return (str);
}
