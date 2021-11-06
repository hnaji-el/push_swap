/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:23:35 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/11/06 19:33:14 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_operation(char *prefix, char *suffix)
{
	ft_putstr(prefix);
	ft_putstr(suffix);
	write(1, "\n", 1);
}

void	swap(t_stack *stack, int print)
{
	int		temp;

	if (stack->length < 2)
		return ;
	temp = stack->top->data;
	stack->top->data = stack->top->next->data;
	stack->top->next->data = temp;
	if (print == 1)
		print_operation("s", stack->name);
}

int	push_(t_stack *stack_1, t_stack *stack_2)
{
	int		data;
	int		index;

	if (stack_2->length == 0)
		return (0);
	data = stack_2->top->data;
	index = stack_2->top->index;
	pop(stack_2);
	if (push(data, stack_1) == -1)
		return (-1);
	stack_1->top->index = index;
	print_operation("p", stack_1->name);
	return (0);
}

void	rotate(t_stack *stack, int print)
{
	if (stack->length < 2)
		return ;
	stack->top = stack->top->next;
	if (print == 1)
		print_operation("r", stack->name);
}

void	reverse_rotate(t_stack *stack, int print)
{
	if (stack->length < 2)
		return ;
	stack->top = stack->top->prev;
	if (print == 1)
		print_operation("rr", stack->name);
}
