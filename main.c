#include "fdf.h"

int main(int argc, char **argv)
{
	int	fd = 0;

	if (argc == 2)
	{	
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			error_handle("ERROR OPEN FILE!\n");
			return (0);
		}
		char *ptr = get_next_line(fd);

		while (ptr)
		{
			printf("%s", ptr);
			ptr = get_next_line(fd);
		}
	}
	return (0);
}
