#include "fdf.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_map	*m;
	t_view	*v;

	(void)m;
	(void)fd;
	(void)argv;
	(void)v;
	if (argc != 2)
	{
		error_handle("Usage: ./fdf <file>\n", 1);
	}

	v = (t_view *)malloc(sizeof(t_view));
	if (!v)
		error_handle("Bad alloc *view*!\n", 1);

	v->map = init_matrix(argv[1]);
	init_window(v);
	return (0);
}
