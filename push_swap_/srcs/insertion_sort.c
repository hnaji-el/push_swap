
#include "../includes/push_swap.h"

void	insertion_sort(int	*arr, int n)
{
	int		hole;
	int		value;
	int		i;

	i = 1;
	while (i <= n - 1)
	{
		value = arr[i];
		hole = i;
		while (hole > 0 && arr[hole - 1] > value)
		{
			arr[hole] = arr[hole - 1];
			hole -= 1;
		}
		arr[hole] = value;
		i++;
	}
}
