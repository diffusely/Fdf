#include "fdf.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_map	m;
	t_view	v;

	(void)m;
	(void)fd;
	(void)argv;
	(void)v;
	if (argc != 2)
	{
		error_handle("Usage: ./fdf <file>\n", 1);
	}

	init_matrix(&m , argv[1]);
	//print(m);
	//free_matrix(&m);
	
	//draw_map(m, &v);
	init_window(&m, &v);
	//free_matrix(&m);
	return (0);
}
