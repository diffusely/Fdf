/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:58:42 by noavetis          #+#    #+#             */
/*   Updated: 2025/03/24 16:06:49 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line.h"
# include "mlx.h"
# include "libft.h"

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>

void	open_file(int *fd, const char* file_name);
void	error_handle(char *message);
void	valid_map(char *message);

#endif