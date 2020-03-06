#include "array_int.h"

void		arr_set(int *arr, int index, int nbr)
{
	if (index < ARR_LEN && index >= 0)
		arr[index + 1] = nbr;
}
