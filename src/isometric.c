/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalitha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:00:59 by ltalitha          #+#    #+#             */
/*   Updated: 2020/03/06 18:47:58 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_structs.h"

int		isometric(float *x, float *y, int z, float angle)
{
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
	return (1);
}
