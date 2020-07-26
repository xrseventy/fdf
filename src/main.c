/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoze <gdoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:08:02 by gdoze             #+#    #+#             */
/*   Updated: 2020/07/17 16:07:18 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_structs.h"
#include "key_macos.h"

void	default_value(t_fdf *data)
{
	data->zoom = 30;
	data->z_zoom = 1;
	data->is_iso = 100;
	data->angle = 0.523599;
	data->window = 1000;
	data->shift_x = data->window / 2;
	data->shift_y = data->window / 2;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr,\
			data->window, data->window, "fdf");
}

void	keyboard_plus(int key, t_fdf *data)
{
	if (key == MAIN_PAD_PLUS || key == NUM_PAD_PLUS)
		data->zoom += 1;
	if (key == MAIN_PAD_MINUS || key == NUM_PAD_MINUS)
		data->zoom -= 1;
	if (key == NUM_PAD_5 || key == MAIN_PAD_5)
		data->is_iso = (data->is_iso) ? 0 : 1;
	if (key == NUM_PAD_8 || key == MAIN_PAD_8)
		data->z_zoom += 1;
	if (key == NUM_PAD_2 || key == MAIN_PAD_2)
		data->z_zoom -= 1;
	if (key == NUM_PAD_4 || key == MAIN_PAD_4)
		data->angle += 0.05;
	if (key == NUM_PAD_6 || key == MAIN_PAD_6)
		data->angle -= 0.05;
	if (key == WHITE_SPACE)
		data->is_iso = (data->is_iso) ? 0 : 1;
}

void	key_esc(int key, t_fdf *data)
{
	if (key == MAIN_PAD_ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data);
		exit(0);
	}
}

int		keyboard(int key, t_fdf *data)
{
	if (key == ARROW_UP)
		data->shift_y -= 10;
	if (key == ARROW_DOWN)
		data->shift_y += 10;
	if (key == ARROW_LEFT)
		data->shift_x -= 10;
	if (key == ARROW_RIGHT)
		data->shift_x += 10;
	keyboard_plus(key, data);
	key_esc(key, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int		main(int argc, char **argv)
{
	t_fdf	*data;
	int		fd;

	if (argc == 2)
	{
		if (!((fd = open(argv[1], O_RDONLY)) >= 0))
		{
			ft_putstr("usage: ./fdf map.fdf\n");
			return (0);
		}
		data = (t_fdf *)malloc(sizeof(t_fdf));
		open_file(argv[1], data);
		default_value(data);
		draw(data);
		mlx_hook(data->win_ptr, 2, 0, keyboard, data);
		mlx_loop(data->mlx_ptr);
		close(fd);
	}
	return (0);
}
