/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoze <gdoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:08:02 by gdoze             #+#    #+#             */
/*   Updated: 2020/03/02 15:23:41 by gdoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_structs.h"


int     deal_key(int key, t_fdf *data) //бонусная часть для кнопок
{
	printf("%d\n", key);
	if (key == 126)
	{
		data->shift_y -=10;
	}
	if (key == 125)
	{
		data->shift_y +=10;
	}
	if (key == 123)
	{
		data->shift_x -=10;
	}
	if (key == 124)
	{
		data->shift_x +=10;
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int main(int argc, char **argv)
{

	t_fdf *data;
//	int i;
//	int j;

	//i = 0;
	data = (t_fdf*)malloc(sizeof(t_fdf));
	read_file(argv[1], data);
//	if(argc < 1)
//		exit(0);
//	while(i < data->height)
//	{
//		j = 0;
//		while(j < data->width)
//		{
//			printf("%2d ", data->z_coordinate[i][j]);
//			j++;
//		}
//		printf("\n");
//		i++;
//	}
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->zoom = 20;
	//bresenham(10, 10, 600, 300, data);
	draw(data);
//	mlx_pixel_put(data->mlx_ptr, data->win_ptr, (int)x, (int)y, #color);
	mlx_key_hook(data->win_ptr, deal_key, data); //для бонусов
	mlx_loop(data->mlx_ptr); //бесконечный цикл, что после рисовки окно не схлопнулось
}