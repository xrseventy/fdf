/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoze <gdoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:08:02 by gdoze             #+#    #+#             */
/*   Updated: 2020/03/01 19:55:49 by gdoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_structs.h"

int	deal_key(int key, void *data)
{
	ft_printf("%d", key);
	return (0);
}

int main(int argc, char **argv)
{
	t_fdf *data;

	data = (t_fdf*)malloc(sizeof(t_fdf));
	read_file(argv[1], data);
	data->mlx_ptr = mlx_init(); //инициализация окна
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF"); //открыли окно с нужными параметрами

	bresenham(10, 10, 600, 300, data);
	mlx_key_hook(data->win_ptr, deal_key, NULL); //для бонусов
	mlx_loop(data->mlx_ptr); //бесконечный цикл, что после рисовки окно не схлопнулось
}