/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:10:01 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/11/04 11:46:26 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
