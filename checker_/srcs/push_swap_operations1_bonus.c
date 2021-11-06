/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:23:35 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/11/04 15:08:27 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	swap(t_stack *stack)
{
	int		temp;

	if (stack->length < 2)
		return ;
	temp = stack->top->data;
	stack->top->data = stack->top->next->data;
	stack->top->next->data = temp;
}

int	push_(t_stack *stack_1, t_stack *stack_2)
{
	int		data;

	if (stack_2->length == 0)
		return (0);
	data = stack_2->top->data;
	pop(stack_2);
	if (push(data, stack_1) == -1)
		return (-1);
	return (0);
}

void	rotate(t_stack *stack)
{
	if (stack->length < 2)
		return ;
	stack->top = stack->top->next;
}

void	reverse_rotate(t_stack *stack)
{
	if (stack->length < 2)
		return ;
	stack->top = stack->top->prev;
}
