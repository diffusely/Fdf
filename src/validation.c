/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:59:07 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/14 16:22:45 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_handle(char *message, int flag)
{
	if (flag)
		ft_putstr_fd(message, 2);
	else
		perror(message);
	exit(EXIT_FAILURE);
}

void	valid_map(char *message)
{
	int	size;

	size = ft_strlen(message);
	if (size < 4 || message[size - 4] != '.' || message[size - 3] != 'f'
		|| message[size - 2] != 'd' || message[size - 1] != 'f')
	{
		error_handle("File format is not .fdf!\n", 1);
	}
}

void	fd_close(int fd)
{
	if (fd == -1)
	{
		error_handle("System error", 0);
	}
	close(fd);
}

void	free_matrix(t_map *m)
{
	int	i;

	i = 0;
	while (i < m->height)
	{
		free(m->mt[i]);
		m->mt[i] = NULL;
		i++;
	}
	free(m->mt);
	m->mt = NULL;
}
