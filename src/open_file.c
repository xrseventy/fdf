/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoze <gdoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:11:06 by gdoze             #+#    #+#             */
/*   Updated: 2020/07/17 18:01:25 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_structs.h"

int		get_height(char *file_name)
{
	char	*string;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd, &string))
	{
		height++;
		free(string);
	}
	free(string);
	close(fd);
	return (height);
}

int		get_width(char *file_name)
{
	int		width;
	int		fd;
	char	*string;

	fd = open(file_name, O_RDONLY, 0);
	get_next_line(fd, &string);
	width = ft_wdcounter(string, ' ');
	free(string);
	close(fd);
	return (width);
}

void	fill_matrix(int *z_string, char *line)
{
	char	**nums;
	int		i;

	nums = ft_strsplit(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_string[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	open_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*string;
	int		i;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->z_coordinate = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->z_coordinate[i++] = (int*)malloc(sizeof(int) * (data->width + 1));
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &string))
	{
		fill_matrix(data->z_coordinate[i], string);
		free(string);
		i++;
	}
	free(string);
	close(fd);
}
