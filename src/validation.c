/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:59:07 by noavetis          #+#    #+#             */
/*   Updated: 2025/03/27 17:43:19 by noavetis         ###   ########.fr       */
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
	if (message[size - 4] != '.' || message[size - 3] != 'f'
		|| message[size - 2] != 'd' || message[size - 1] != 'f')
	{
		error_handle("File format is not .fdf!\n", 1);
	}
}

void	fd_close(int fd)
{
	if (close(fd) == -1)
	{
		error_handle("System error", 0);
	}
	close(fd);
}
