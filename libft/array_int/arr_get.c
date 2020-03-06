#include "array_int.h"

int		arr_get(int *arr, int index)
{
	if (index < ARR_LEN && index >= 0)
		return (arr[index + 1]);
	else
		return (0);
}
