/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:59:07 by noavetis          #+#    #+#             */
/*   Updated: 2025/03/24 16:12:41 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_handle(char *message)
{
	ft_putstr_fd(message, 2);
	exit(1);
}

void	valid_map(char *message)
{
	int	size;

	size = ft_strlen(message);
	if (size <= 4)
	{
		error_handle("FILE INPUT IS LESS THAN 5 CHARACTERS!\n");	
	}
	if (message[size - 4] != '.' || message[size - 3] != 'f'
		|| message[size - 2] != 'd' || message[size - 1] != 'f')
	{
		error_handle("FILE FORMAT IS NOT .FDF!\n");
	}
}

void	open_file(int *fd, const char* file_name)
{
	*fd = open(file_name, O_RDONLY);
	if (*fd == -1)
	{
		error_handle("ERROR OPEN FILE!\n");
		perror("System error");
		exit(EXIT_FAILURE);
	}
}
