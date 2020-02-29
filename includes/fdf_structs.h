/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoze <gdoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:01:05 by gdoze             #+#    #+#             */
/*   Updated: 2020/02/29 13:07:31 by gdoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
# define FDF_STRUCTS_H

#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

typedef struct		s_fdf
{
	int width;
	int height;
	int z_coordinate; //z_matrix

	void *mlx_ptr;
	void *win_ptr;
}					t_fdf;

#endif