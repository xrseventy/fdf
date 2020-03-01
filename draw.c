/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoze <gdoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 19:01:25 by gdoze             #+#    #+#             */
/*   Updated: 2020/03/01 19:41:50 by gdoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_structs.h"
#define MAX(a, b) (a > b ? a : b) //
#define MOD(a) (a < 0) ? -a : a

float mod(float i) //необходимо находить значение не по максимуму, а по модулю. на случай отрицаткльных значений
{
	return (i < 0) ? -i : i;
}
void	bresenham(float x, float y, float x1, float y1, t_fdf *data) //передаем координаты 1,1 3,12
{
	float x_step;
	float y_step;
	int max;

	x_step = x1 - x; //2
	y_step = y1 - y; // 11

	//за каждый проход цикла нужно распечатывать пиксели, но шаг не более 1 пикселя. Чтобы не было разрыва

	//каждый шаг нужно разделить на максимальное число
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;

	while((int)(x - x1) || (int)(y - y1)) //размещение пикселя на поле, цикл останавливается когда обе координаты равны 1
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xffffff);
		x += x_step;
		y += y_step;
	}

}

//void draw(t_fdf *data)
//{
//	int x;
//	int y;
//
//	y = 0;
//	while(y < data->height)
//	{
//		x = 0;
//		while (x < data->width)
//		{
//			bresenham(x, y, x + 1, y, data);
//		}
//	}
//}
