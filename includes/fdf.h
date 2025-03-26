/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:58:42 by noavetis          #+#    #+#             */
/*   Updated: 2025/03/26 20:33:35 by noavetis         ###   ########.fr       */
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
	char	**map;
}	t_map;

typedef struct s_view
{
	void	*mlx;
	void	*win;
}	t_view;

void	open_file(int *fd, const char *file_name);
void	error_handle(char *message, int flag);
void	valid_map(char *message);
void	ft_swap(int *a, int *b);
void	draw_line(t_coord start, t_coord end, t_view view);

char	**init_matrix(t_view v, int fd);

#endif