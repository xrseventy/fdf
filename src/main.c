/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoze <gdoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:08:02 by gdoze             #+#    #+#             */
/*   Updated: 2020/03/02 17:17:03 by gdoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_structs.h"


int     deal_key(int key, t_fdf *data) //бонусная часть для кнопок
{
	printf("%d", key);
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

int main(int argc, char **argv) {

	t_fdf *data;
	int fd;

	if(argc == 2)
	{
		if (!((fd = open(argv[1], O_RDONLY)) >= 0))
			ft_putstr("usage: ./fdf map.fdf\n");
		data = (t_fdf *)malloc(sizeof(t_fdf));
		read_file(*++argv, data);
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(data->mlx_ptr, 600, 600, "FDF");
		data->zoom = 1;
		draw(data);
		mlx_key_hook(data->win_ptr, deal_key, data); //для бонусов
		mlx_loop(data->mlx_ptr); //бесконечный цикл, что после рисовки окно не схлопнулось
		close(fd);
	}
	return(0);
}