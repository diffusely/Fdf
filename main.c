#include "fdf.h"

int main(int argc, char **argv)
{
	int	fd;

	if (argc == 2)
	{	
		(void)argv;
		char	*name = ft_strjoin("maps/", argv[1]);
		fd = open(name, O_RDONLY);
		if (fd == -1)
		{
			printf("ERROR OPEN FILE!\n");
			return (-1);
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
