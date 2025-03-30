/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:09:37 by noavetis          #+#    #+#             */
/*   Updated: 2025/03/30 23:15:50 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print(t_map m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m.height)
	{
		j = 0;
		while (j < m.width)
		{
			printf("%d ",m.matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	m;
	t_view	v;

	(void)m;
	(void)fd;
	(void)argv;
	if (argc != 2)
	{
		error_handle("Usage: ./fdf <file>\n", 1);
	}

	init_matrix(&m , argv[1]);
	print(m);
	//free_matrix(&m);
	
	//draw_map(m, &v);
	init_window(&m, &v);
	free_matrix(&m);
	return (0);
}
