/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoze <gdoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:01:05 by gdoze             #+#    #+#             */
/*   Updated: 2020/07/20 19:37:18 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
# define FDF_STRUCTS_H

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"

typedef struct	s_fdf
{
	int			width;
	int			height;
	int			zoom;
	int			color;
	int			**z_coordinate;
	int			is_iso;
	float		angle;
	int			window;
	int			shift_x;
	int			shift_y;

	void		*mlx_ptr;
	void		*win_ptr;
	int			z_zoom;
}				t_fdf;

void			open_file(char *file_name, t_fdf *data);
void			bline(float x, float y, float x1, float y1, t_fdf *data);
void			draw(t_fdf *data);
void			default_value(t_fdf *data);
void			keyboard_plus(int key, t_fdf *data);
void			key_esc(int key, t_fdf *data);
int				isometric(float *x, float *y, int z, float angle);
void			read_line(int fd, t_fdf *data);

#endif
