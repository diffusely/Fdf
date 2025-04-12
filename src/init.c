/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:30:01 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/12 19:52:28 by noavetis         ###   ########.fr       */
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

static void	init_val(t_map *m, const char *file_name)
{
	m->height = get_height(file_name);
	m->width = get_width(file_name);
	m->mt = (int **)malloc(m->height * sizeof(int *));
	if (!m->mt)
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

t_map	*init_matrix(const char *file_name)
{
	t_map	*m;
	int		fd;
	int		i;

	m = (t_map *)malloc(sizeof(t_map));
	if (!m)
		error_handle("Bad alloc *matrix*!\n", 1);
	fd = open_file(file_name);
	init_val(m, file_name);
	i = 0;
	while (i < m->height)
	{
		m->mt[i] = init_matrix_line(m->width, fd);
		if (!m->mt[i])
		{
			while (--i >= 0)
				free(m->mt[i]);
			free(m->mt);
			fd_close(fd);
			error_handle("Map is not valid!\n", 1);
		}
		i++;
	}
	return (fd_close(fd), m);
}
