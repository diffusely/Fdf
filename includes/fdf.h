/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:58:42 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/08 18:45:55 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line.h"
# include "mlx.h"
# include "libft.h"

# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

# define WIDTH	1920
# define HEIGHT	1080

# define ESC_KEY 65307
# define ANGLE 0.45
# define ZOOM_IN_KEY 24
# define ZOOM_OUT_KEY 27

typedef struct s_coord
{
	int	x;
	int	y;
	int	z;
	int	color;
	int	rev;
}	t_coord;

typedef struct s_map
{
	int	**matrix;
	int	width;
	int	height;
	t_coord point;
}	t_map;

typedef struct s_view
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
	int		color;
	float	zoom;
	t_map	*map;
}	t_view;

void	ft_swap(int *a, int *b);
int		open_file(const char *file_name);

void	error_handle(char *message, int flag);
void	valid_map(char *message);
void	fd_close(int fd);

void	draw_line(t_coord start, t_coord end, t_view *view);
void	ft_pixel_put(t_view *v, int x, int y, int color);

// init
void	init_matrix(t_map *m, const char *file_name);
int		get_width(const char *file_name);
int		get_height(const char *file_name);
size_t	word_count_sep(const char *str, char *s);
void	free_matrix(t_map *m);

// display
int		key_hook(int keycode, void *param);
void	draw_map(t_map *m, t_view *v);
void	init_window(t_map *m, t_view *v);

// test
void	print(t_map m);

#endif