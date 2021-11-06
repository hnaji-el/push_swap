/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:28:22 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/11/06 20:28:53 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sort_stack_5(t_stack *stack_a, t_stack *stack_b)
{
	int		min_pos;

	min_pos = get_min_pos(stack_a);
	if (min_pos >= 1 && min_pos <= 3)
		min_pos = adjust_min_pos(stack_a, min_pos);
	while (min_pos > 1 && min_pos <= 3)
	{
		rotate(stack_a, 1);
		min_pos--;
	}
	if (min_pos == 4)
	{
		reverse_rotate(stack_a, 1);
		if (stack_a->top->data > stack_a->top->prev->data)
			reverse_rotate(stack_a, 1);
	}
	if (push_(stack_b, stack_a) == -1)
		return (-1);
	sort_stack_4(stack_a, stack_b);
	return (push_(stack_a, stack_b));
}

int	sort_stack_4(t_stack *stack_a, t_stack *stack_b)
{
	int		min_pos;

	min_pos = get_min_pos(stack_a);
	if (min_pos == 2)
		rotate(stack_a, 1);
	while (min_pos > 2 && min_pos <= 4)
	{
		reverse_rotate(stack_a, 1);
		min_pos++;
	}
	if (push_(stack_b, stack_a) == -1)
		return (-1);
	sort_stack_3(stack_a);
	return (push_(stack_a, stack_b));
}

void	sort_stack_3(t_stack *stack)
{
	t_node	*top;
	int		max_pos;

	max_pos = 1;
	top = stack->top;
	if (top->data < top->next->data)
		max_pos = 2;
	if ((max_pos == 1 && top->prev->data > top->data)
		|| (max_pos == 2 && top->prev->data > top->next->data))
		max_pos = 3;
	if (max_pos == 1)
		rotate(stack, 1);
	if (max_pos == 2)
		reverse_rotate(stack, 1);
	if (stack->top->data > stack->top->next->data)
		swap(stack, 1);
}

int	sort_small_stack(t_stack *stack_a, t_stack *stack_b)
{
	int		ret;

	ret = 0;
	if (stack_a->length == 2)
		swap(stack_a, 1);
	if (stack_a->length == 3)
		sort_stack_3(stack_a);
	if (stack_a->length == 4)
		ret = sort_stack_4(stack_a, stack_b);
	if (stack_a->length == 5)
		ret = sort_stack_5(stack_a, stack_b);
	if (ret == -1)
		put_error(2);
	return (ret);
}
