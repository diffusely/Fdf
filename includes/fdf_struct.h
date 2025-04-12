/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:37:32 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/12 19:50:04 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H

# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include <unistd.h>

typedef struct s_point
{
	float	i;
	float	j;
}	t_point;

typedef struct s_coord
{
	int	x;
	int	y;
	int	z;
	int	color;
	int	s_color;
	int	e_color;
}	t_coord;

typedef struct s_map
{
	int		**mt;
	int		width;
	int		height;
	t_coord	point;
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
	float	rot;
	int		flag;
	int		t_flag;
	t_map	*map;
}	t_view;

#endif