#include "fdf.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_view	*v;

	(void)fd;
	(void)argv;
	if (argc != 2)
	{
		error_handle("Usage: ./fdf <file>\n", 1);
	}

	valid_map(argv[1]);
	v = (t_view *)malloc(sizeof(t_view));
	if (!v)
		error_handle("Bad alloc *view*!\n", 1);

	v->map = init_matrix(argv[1]);
	init_window(v);
	return (0);
}
