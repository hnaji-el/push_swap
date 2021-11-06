/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:37:49 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/11/06 19:34:01 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_on_two_stack(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a, 0);
	swap(stack_b, 0);
	if (stack_a->length > 1 || stack_b->length > 1)
		write(1, "ss\n", 3);
}

void	rotate_on_two_stack(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	if (stack_a->length > 1 || stack_b->length > 1)
		write(1, "rr\n", 3);
}

void	rev_rotate_on_two_stack(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a, 0);
	reverse_rotate(stack_b, 0);
	if (stack_a->length > 1 || stack_b->length > 1)
		write(1, "rrr\n", 4);
}
