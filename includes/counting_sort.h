/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting_sort.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:15:19 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/11/04 11:25:11 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COUNTING_SORT_H
# define COUNTING_SORT_H

typedef struct	s_data
{
	int		*count_arr;
	int		*dup_arr;
	int		min;
	int		max;
}				t_data;

int		counting_sort(int *arr, int n);
int		get_min(int	*arr, int n);
int		get_max(int	*arr, int n);
int		free_data(t_data *data);

#endif
