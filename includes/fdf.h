/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:58:42 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/12 21:00:13 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "fdf_struct.h"
# include "get_next_line.h"
# include "mlx.h"
# include "libft.h"

# define WIDTH	1200
# define HEIGHT	800
# define SIZE 100

# define ESC_KEY 65307
# define ZOOM_IN_KEY 4
# define ZOOM_OUT_KEY 5

# define ANGLE 0.5544
# define PI 3.1415926535

# define SPACE 32
# define UP 61
# define DOWN 45
# define A 97
# define S 115
# define D 100
# define W 119
# define R 114
# define T 116
# define E 101

# define SCOLOR 0xFF0000
# define ECOLOR 0xFFA500

void	fill_background(t_view *v, int color);
int		interpolate_color(int c1, int c2, float t);

void	draw_map(t_view *v, int c1, int c2);

int		get_width(const char *file_name);
int		get_height(const char *file_name);
void	point_up(t_view *v, int dir);
void	free_all(t_view *v);

int		key_hook(int keycode, t_view *v);
int		close_window(void *param);
void	new_img(t_view	*v);
int		mouse_hook(int button, int x, int y, void *param);

void	init_window(t_view *v);
t_map	*init_matrix(const char *file_name);

void	draw_line(t_coord start, t_coord end, t_view *view);

int		iso_x(int x, int y, int flag);
int		iso_y(int x, int y, int z, int flag);
void	rotation(float *x, float *y, float *z, t_view *view);

void	ft_swap(int *a, int *b);
int		open_file(const char *file_name);
size_t	word_count_sep(const char *str, char *s);
void	ft_pixel_put(t_view *v, int x, int y, int color);

void	error_handle(char *message, int flag);
void	valid_map(char *message);
void	fd_close(int fd);
void	free_matrix(t_map *m);

#endif