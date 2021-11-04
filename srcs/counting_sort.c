
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Counting sort is efficient if the range of input data is not significantly
 * greater than the number of objects to be sorted.
 * Consider the situation where the input sequence is between range 1 to 10K
 * and the data is 10, 5, 10K, 5K. 
 * There is no comparison between any elements,
 * so it is better than comparison based sorting techniques.
 * But, it is bad if the integers are very large because the array of that size should be made.
 * ------- complexity -------
 * 1. time complexity
 * O(n+k) in all cases, where n is the number of elements and k is the range of input.
 * 2. space complexity
 * O(k)
 * ------ stability --------
 * stable
 */

typedef struct	s_data
{
	int		*count_arr;
	int		*dup_arr;
	int		min;
	int		max;
}				t_data;

int	get_max(int	*arr, int n)
{
	int		max;
	int		i;

	i = 0;
	max = arr[0];
	while (++i <= n - 1)
	{
		if (max < arr[i])
			max = arr[i];
	}
	return (max);
}

int	get_min(int	*arr, int n)
{
	int		min;
	int		i;

	i = 0;
	min = arr[0];
	while (++i <= n - 1)
	{
		if (min > arr[i])
			min = arr[i];
	}
	return (min);
}

t_data	*create_and_initialize_data(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->count_arr = (void *)0;
	data->dup_arr = (void *)0;
	data->min = 0;
	data->max = 0;
	return (data);
}

int	free_data(t_data *data)
{
	if (data->count_arr != NULL)
		free(data->count_arr);
	if (data->dup_arr != NULL)
		free(data->dup_arr);
	free(data);
	return (-1);
}

void	sort_original_array(int *arr, int i, t_data *data)
{
	int		i_count;

	while (--i >= 0)
	{
		i_count = data->dup_arr[i] - data->min;
		arr[data->count_arr[i_count] - 1] = data->dup_arr[i];
		data->count_arr[i_count] -= 1;
	}
}

void	fill_count_array(int *arr, int n, t_data *data)
{
	int		i;

	i = -1;
	while (++i <= n - 1)
		data->count_arr[arr[i] - data->min] += 1;
	i = 0;
	while (++i <= (data->max - data->min))
		data->count_arr[i] += data->count_arr[i - 1];
}

int	counting_sort(int *arr, int n)
{
	t_data	*data;

	if (arr == NULL)
		return (-1);
	data = create_and_initialize_data();
	if (data == NULL)
		return (-1);
	data->dup_arr = (int *)malloc(sizeof(int) * n);
	if (data->dup_arr == NULL)
		return (free_data(data));
	memcpy(data->dup_arr, arr, sizeof(int) * n);
	data->max = get_max(arr, n);
	data->min = get_min(arr, n);
	data->count_arr = (int *)calloc(data->max - data->min + 1, sizeof(int));
	if (data->count_arr == NULL)
		return (free_data(data));
	fill_count_array(arr, n, data);
	sort_original_array(arr, n, data);
	free_data(data);
	return (0);
}
