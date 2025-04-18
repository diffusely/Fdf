/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:30:01 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/14 16:31:51 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	*init_matrix_line(int width, int fd)
{
	char	**ptr;
	char	*r;
	int		*line;
	int		i;

	r = get_next_line(fd);
	if (!r)
		return (NULL);
	ptr = ft_split(r, ' ');
	line = (int *)malloc(width * sizeof(int));
	if (!line)
		error_handle("Bad alloc *line*!\n", 1);
	i = 0;
	while (i < width)
	{
		line[i] = ft_atoi(ptr[i]) * 10;
		i++;
	}
	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	return (free(r), free(ptr), line);
}

static int	init_val(t_map *m, const char *file_name, t_view *v, int fd)
{
	if (fd == -1)
	{
		free(m);
		free(v);
		error_handle("System error", 0);
	}
	m->width = get_width(file_name);
	if (m->width == -1)
		return (free(m), free(v), -1);
	m->height = get_height(file_name);
	m->mt = (int **)malloc(m->height * sizeof(int *));
	if (!m->mt)
		return (free(v), fd_close(fd), -1);
	return (1);
	error_handle("Bad alloc *matrix*!\n", 1);
}

void	init_window(t_view *v)
{
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, WIDTH, HEIGHT, "FdF");
	v->img = mlx_new_image(v->mlx, WIDTH, HEIGHT);
	v->addr = mlx_get_data_addr(v->img, &v->bpp, &v->ll, &v->endian);
	v->zoom = 0.3f;
	v->flag = 0;
	v->t_flag = 1;
	v->map->point.x = 0;
	v->map->point.y = 0;
	v->rot = 0;
	fill_background(v, 0x0A0E2A);
	draw_map(v, SCOLOR, ECOLOR);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	mlx_hook(v->win, 2, 1L << 0, key_hook, v);
	mlx_mouse_hook(v->win, mouse_hook, v);
	mlx_hook(v->win, 17, 0, close_window, v);
	mlx_loop(v->mlx);
}

t_map	*init_matrix(const char *file_name, t_view *v)
{
	t_map	*m;
	int		fd;
	int		i;

	m = (t_map *)malloc(sizeof(t_map));
	if (!m)
		error_handle("Bad alloc *matrix*!\n", 1);
	fd = open(file_name, O_RDONLY);
	if (init_val(m, file_name, v, fd) == -1)
		error_handle("Map width incorrect!\n", 1);
	i = -1;
	while (++i < m->height)
	{
		m->mt[i] = init_matrix_line(m->width, fd);
		if (!m->mt[i])
		{
			while (--i >= 0)
				free(m->mt[i]);
			free(m->mt);
			free(v);
			fd_close(fd);
			error_handle("Bad alloc *matrix*!\n", 1);
		}
	}
	return (fd_close(fd), m);
}
