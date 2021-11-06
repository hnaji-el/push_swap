/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:29:01 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/11/06 20:29:47 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_min_pos(t_stack *stack)
{
	t_node	*top;
	t_node	*bottom;
	int		min_pos;

	min_pos = 1;
	top = stack->top;
	bottom = top->prev;
	if (stack->length == 5)
		bottom = bottom->prev;
	if (top->data > top->next->data)
		min_pos = 2;
	if ((min_pos == 1 && top->data > bottom->prev->data)
		|| (min_pos == 2 && top->next->data > bottom->prev->data))
		min_pos = 3;
	if ((min_pos == 1 && top->data > bottom->data)
		|| (min_pos == 2 && top->next->data > bottom->data)
		|| (min_pos == 3 && bottom->prev->data > bottom->data))
		min_pos = 4;
	return (min_pos);
}

int	adjust_min_pos(t_stack *stack_a, int min_pos)
{
	t_node	*top;
	t_node	*bottom;

	top = stack_a->top;
	bottom = stack_a->top->prev;
	if (min_pos == 1 && top->data > bottom->data)
		reverse_rotate(stack_a, 1);
	else if (min_pos == 2 && top->next->data > bottom->data)
		reverse_rotate(stack_a, 1);
	else if (min_pos == 3 && top->next->next->data > bottom->data)
		reverse_rotate(stack_a, 1);
	else
		return (min_pos);
	return (0);
}
