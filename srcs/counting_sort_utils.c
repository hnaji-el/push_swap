/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting_sort_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:12:10 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/11/04 11:22:54 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	free_data(t_data *data)
{
	if (data->count_arr != NULL)
		free(data->count_arr);
	if (data->dup_arr != NULL)
		free(data->dup_arr);
	free(data);
	return (-1);
}

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
