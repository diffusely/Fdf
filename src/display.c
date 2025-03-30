/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 22:15:51 by noavetis          #+#    #+#             */
/*   Updated: 2025/03/30 23:38:16 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw()
{
	
}

int	key_hook(int keycode, void *param)
{
	if (keycode == ESC_KEY)
	{
		mlx_loop_end(param);
	}
	return (0);
}

void	init_window(t_map *m, t_view *v)
{
	(*v).mlx = mlx_init();
	(*v).win = mlx_new_window((*v).mlx, WIDTH, HEIGHT, "Fdf");

	draw_map(m, v);
	mlx_key_hook((*v).win, key_hook, (*v).mlx); 
	mlx_loop((*v).mlx);
}



int iso_x(int x, int y) {
    return (x - y) * cos(ANGLE);
}

int iso_y(int x, int y, int z) {
    return (x + y) * sin(ANGLE) - z;
}

void	draw_map(t_map *m, t_view *v)
{
	t_coord	st;
	t_coord	end;
	
	int	i;
	int	j;

	i = 0;
	int offset_x = WIDTH / 2 - (m->width * 10) / 2;
    int offset_y = HEIGHT / 2 - (m->height * 10) / 2;

    while (i < m->height)
    {
        j = 0;
        while (j < m->width)
        {
            int z = m->matrix[i][j];

            st.x = iso_x(j * 10, i * 10) + offset_x;
            st.y = iso_y(j * 10, i * 10, z) + offset_y;
            if (j < m->width - 1) {
                int z_right = m->matrix[i][j + 1];
                end.x = iso_x((j + 1) * 10, i * 10) + offset_x;
                end.y = iso_y((j + 1) * 10, i * 10, z_right) + offset_y;
                draw_line(st, end, *v);
            }

            if (i < m->height - 1) {
                int z_down = m->matrix[i + 1][j];
                end.x = iso_x(j * 10, (i + 1) * 10) + offset_x;
                end.y = iso_y(j * 10, (i + 1) * 10, z_down) + offset_y;
                draw_line(st, end, *v);
            }

            j++;
        }
        i++;
    }

}
