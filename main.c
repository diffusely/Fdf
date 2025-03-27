/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:09:37 by noavetis          #+#    #+#             */
/*   Updated: 2025/03/27 21:12:17 by noavetis         ###   ########.fr       */
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
			printf("%d",m.arr[i][j]);
			j++;
		}
		i++;
	}
}


int	key_hook(int keycode, void *param)
{
	if (keycode == ESC_KEY)
	{
		mlx_loop_end(param);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	m;
	//t_view	v;

	(void)m;
	(void)fd;
	(void)argv;
	//(void)v;
	if (argc != 2)
	{
		error_handle("Usage: ./fdf <file>\n", 1);
	}

	m.width = get_width(argv[1]);
	m.height = get_height(argv[1]);
	
	//fd = open_file(argv[1]);


	// init matrix
	//m.arr = init_matrix(v, fd);
	//print(m);

	
	// mlx
    //v.mlx = mlx_init();
    //v.win = mlx_new_window(v.mlx, WIDTH, HEIGHT, "MiniLibX Window");
	//mlx_key_hook(v.win, key_hook, v.mlx); 
    //mlx_loop(v.mlx);
	
	return (0);
}
