/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoze <gdoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:01:05 by gdoze             #+#    #+#             */
/*   Updated: 2020/03/02 15:22:41 by gdoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
# define FDF_STRUCTS_H

# include "../libft/libft.h"
#include <stdio.h>
#include "../minilibx_macos/mlx.h"
#include <math.h>

typedef struct
{
	int width;
	int height;
	int **z_coordinate; //z_matrix
	int zoom; //делает рисунок крупнее
	int color;
	int shift_x;
	int shift_y;

	void *mlx_ptr;//найти зачем эта переменная
	void *win_ptr; //ссылка на окно

}					t_fdf;

void	read_file(char *file_name, t_fdf *data);
void	bresenham(float x, float y, float x1, float y1, t_fdf *data);
void	draw(t_fdf *data);
#endif