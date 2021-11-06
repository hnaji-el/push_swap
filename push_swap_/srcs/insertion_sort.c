/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:29:49 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/11/06 19:30:28 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
