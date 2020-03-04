/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoze <gdoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 19:01:25 by gdoze             #+#    #+#             */
/*   Updated: 2020/03/04 19:27:06 by gdoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_structs.h"
#define MAX1(a, b) (a > b ? a : b) //
#define MOD(a) (a < 0) ? -a : a

float mod(float i) //необходимо находить значение не по максимуму, а по модулю. на случай отриц значений
{
	return (i < 0) ? -i : i;
}


void    isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void    bresenham(float x, float y, float x1, float y1, t_fdf *data)
{
	float x_step;
	float y_step;
	int max;
	int z; //переменные для цвета
	int z1;

	z = data->z_coordinate[(int)y][(int)x];
	z1 = data->z_coordinate[(int)y1][(int)x1];
	//добавляем zoom
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;

	//цвета либо красный, либо белый
	data->color = (z || z1) ? 0xe80c0c : 0xffffff;
//	data->color = (z1) ? 0xe80c0c : 0xffffff;

//to 3d
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);

	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;

//	x += 150;
//	y += 150;
//	x1 += 150;
//	y1 += 150;


	x_step = x1 - x;
	y_step = y1 - y;
//за каждый проход цикла нужно распечатывать пиксели, но шаг не более 1 пикселя. Чтобы не было разрыва
//
//	//каждый шаг нужно разделить на максимальное число
	max = MAX1(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;

	while ((int)(x - x1) || (int)(y - y1))//размещение пикселя на поле, цикл останавливается когда обе координаты равны 1
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void    draw(t_fdf *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data);//горизонтальная линия
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data);//веритикальная линия
			x++;
		}
		y++;
	}
}