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

#include "../includes/fdf_structs.h"

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
	width = ft_wdcounter(string, ' ');
	free(string);
	close(fd);
	return(width);
}

void fill_matrix(int *z_string, char *line)
{
    char **nums;
    int i;

    nums = ft_strsplit(line, ' '); // делим строку
    i = 0;
    while (nums[i])
    {
        z_string[i] = ft_atoi(nums[i]); //записываем в массив переводя в цифры
        free(nums[i]);
        i++;
    }
    free(nums);
}
void read_file(char *file_name, t_fdf *data)
{
	int fd;
	char *string;
	int i;

	data->height = get_height(file_name); //получили высоту и ширину
	data->width = get_width(file_name);
	data->z_coordinate = (int **)malloc(sizeof(int *) * (data->height + 1)); //память под массив строчек
	i = 0;
	while  (i <= data->height)
	    data->z_coordinate[i++] =  (int*)malloc(sizeof(int) * (data->width + 1)); //память под каждую строчку
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &string))
    {
	    fill_matrix(data->z_coordinate[i], string); //происходит запись
	    free(string);
	    i++;
    }
	close(fd);
    data->z_coordinate[i] = NULL;
}
