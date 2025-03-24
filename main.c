#include "fdf.h"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	fd;
		valid_map(argv[1]);
		open_file(&fd, argv[1]);
		char *ptr = get_next_line(fd);

		while (ptr)
		{
			printf("%s", ptr);
			ptr = get_next_line(fd);
		}

		close(fd);
	}
	return (0);
}
