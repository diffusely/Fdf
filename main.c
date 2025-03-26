/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:09:37 by noavetis          #+#    #+#             */
/*   Updated: 2025/03/26 21:07:08 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print(char **m)
{
	int	i;

	i = 0;
	while (m[i])
	{
		ft_putstr_fd(m[i], 1);
		printf("\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	t_coord st;
	t_coord end;
	t_view v;
	char	**m = {0};

	(void)m;
	if (argc != 2)
	{
		error_handle("Usage: ./fdf <file>\n", 1);
	}
	open_file(&fd, argv[1]);
	m = init_matrix(v, fd);
	print(m);

    v.mlx = mlx_init();   
    v.win = mlx_new_window(v.mlx, WIDTH, HEIGHT, "MiniLibX Window");

	for (int i = 0; i < 21; i++)
	{

		for (int j = 0; j < 20; j++)
		{
			st.x = (j * 40) + 150;   //200 220 240 260 ...
			st.y = (i * 40) + 150;
			end.x = (j + 1) * 40 + 150; //220 240 260 280 ...
			end.y = (i * 40) + 150;
			draw_line(st, end, v);
		}
	
		
	}

	for (int i = 0; i < 21; i++)
	{

		for (int j = 0; j < 20; j++)
		{
			st.y = (j * 40) + 150;   //200 220 240 260 ...
			st.x = (i * 40) + 150;
			end.y = (j + 1) * 40 + 150; //220 240 260 280 ...
			end.x = (i * 40) + 150;
			draw_line(st, end, v);
		}
		
	}
    
    

    mlx_loop(v.mlx);
	
	return (0);
}
