/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:30:01 by noavetis          #+#    #+#             */
/*   Updated: 2025/03/26 20:27:09 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**init_matrix(t_view v, int fd)
{
	char	*ptr;
	char	*res;

	(void)v;
	res = get_next_line(fd);
	ptr = res;
	while (ptr)
	{
		ptr = get_next_line(fd);
		if (!ptr)
			break ;
		res = ft_strjoin(res, ptr);
	}
	//ft_putstr_fd(res, 1);
	return (ft_split(res, '\n'));
}
