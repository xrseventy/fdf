/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoze <gdoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:08:02 by gdoze             #+#    #+#             */
/*   Updated: 2020/03/01 18:05:35 by gdoze            ###   ########.fr       */
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
	int i;
	int j;
	i = 0;
	while(i < data->height)
	{
        j = 0;
        while (j < data->width)
        {
            ft_printf("%2d ", data->z_coordinate[i][j]);
            j++;
        }
		ft_printf("\n");
        i++;
    }
}