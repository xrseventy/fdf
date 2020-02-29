/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoze <gdoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:11:06 by gdoze             #+#    #+#             */
/*   Updated: 2020/02/29 13:21:48 by gdoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_structs.h"

int	get_height(char *file_name)
{
	char *string;
	int fd;
	int height;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while(get_next_line(fd, &string))
	{
		height++;
		free(string);
	}
	close(fd);
	return(height);
}

int get_width(char *file_name)
{
	int width;
	int fd;
	char *string;

	fd = open(file_name, O_RDONLY, 0);
	get_next_line(fd, &string);
	width = fd_wdcounter(string, ' ');
	free(string);
	close(fd);
	return(width);
}
void read_file(char *file_name, t_fdf *data)
{
	int fd;
	char *string;

	data->height = get_height(file_name);
	data->width = get_with(file_name);
	data->z_coordinate = (int **)malloc(sizeof(int *) * data->height + 1)
}