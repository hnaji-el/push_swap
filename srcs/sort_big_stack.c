/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 08:41:14 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/11/04 11:24:00 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	copy_stack_into_array(t_stack *stack, int *array)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = stack->top;
	while (i < stack->length)
	{
		array[i] = temp->data;
		temp = temp->next;
		i++;
	}
}

int	sort_stack_by_ith_bit(t_stack *stack_a, t_stack *stack_b, int ith)
{
	int		length;
	int		j;

	j = 0;
	length = stack_a->length;
	while (j < length)
	{
		if ((stack_a->top->index & (1 << ith)) == 0)
		{
			if (push_(stack_b, stack_a) == -1)
				return (-1);
		}
		else
			rotate(stack_a, 1);
		j++;
	}
	while (stack_b->length > 0)
	{
		if (push_(stack_a, stack_b) == -1)
			return (-1);
	}
	return (0);
}	

void	fill_index_in_node(t_node *node, int *array, int size_array)
{
	int		i;

	i = 0;
	while (i < size_array)
	{
		if (node->data == array[i])
		{
			node->index = i;
			break ;
		}
		i++;
	}
}

int	fill_indeces_in_stack_a(t_stack *stack_a)
{
	int		*auxill_arr;
	t_node	*temp;

	temp = stack_a->top;
	auxill_arr = (int *)malloc(sizeof(int) * stack_a->length);
	if (auxill_arr == NULL)
		return (-1);
	copy_stack_into_array(stack_a, auxill_arr);
	if (counting_sort(auxill_arr, stack_a->length) == -1)
		return (-1);
	while (1)
	{
		fill_index_in_node(temp, auxill_arr, stack_a->length);
		temp = temp->next;
		if (temp == stack_a->top)
			break ;
	}
	free(auxill_arr);
	return (0);
}

int	sort_big_stack(t_stack *stack_a, t_stack *stack_b)
{
	int		max;
	int		ith;

	ith = 0;
	max = stack_a->length - 1;
	if (fill_indeces_in_stack_a(stack_a) == -1)
		return (put_error(2));
	while ((max >> ith) != 0)
	{
		if (sort_stack_by_ith_bit(stack_a, stack_b, ith) == -1)
			return (put_error(2));
		ith++;
	}
	return (0);
}
