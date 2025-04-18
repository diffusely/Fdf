/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 02:14:55 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/14 16:24:46 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_view	*v;

	if (argc != 2)
	{
		error_handle("Usage: ./fdf <file>\n", 1);
	}
	valid_map(argv[1]);
	v = (t_view *)malloc(sizeof(t_view));
	if (!v)
		error_handle("Bad alloc *view*!\n", 1);
	v->map = init_matrix(argv[1], v);
	if (!v->map)
	{
		free(v);
		error_handle("Map width incorrect!\n", 1);
	}
	init_window(v);
	return (0);
}
