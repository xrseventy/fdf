#include "../includes/fdf_structs.h"

int		isometric(float *x, float *y, int z, float angle)
{
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
	return (1);
}
