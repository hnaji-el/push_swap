/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:04:13 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/11/04 15:13:38 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack_3(t_stack *stack_a)
{
	int		j;

	j = 1;
	if (stack_a->top->data < stack_a->top->next->data)
		j = 2;
	if (j == 1 && stack_a->top->prev->data > stack_a->top->data)
		j = 3;
	if (j == 2 && stack_a->top->prev->data > stack_a->top->next->data)
		j = 3;
	if (j == 1)
		rotate(stack_a, 1);
	if (j == 2)
		reverse_rotate(stack_a, 1);
	if (stack_a->top->data > stack_a->top->next->data)
		swap(stack_a, 1);
}

//void	sort_stack_4(t_stack *stack_a, t_stack *stack_b)
//{
//}
//
//void	sort_stack_5(t_stack *stack_a, t_stack *stack_b)
//{
//}

int	sort_small_stack(t_stack *stack_a, t_stack *stack_b)
{
	printf("%d\n", stack_b->length);
	if (stack_a->length == 2)
		swap(stack_a, 1);
	if (stack_a->length == 3)
		sort_stack_3(stack_a);
//	if (stack_a->length == 4)
//		sort_stack_4(stack_a, satck_b);
//	if (stack_a->length == 5)
//		sort_stack_5(stack_a, satck_b);
	return (0);
}
