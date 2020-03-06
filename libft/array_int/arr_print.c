#include "array_int.h"

void	arr_print(int *arr)
{
	int i;

	i = 1;
	while (i <= ARR_LEN)
	{
		ft_printf("%d ", arr[i++]);
	}
	ft_printf("\n");
}