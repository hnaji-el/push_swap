/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:46:11 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/11/06 15:53:39 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	stack_a_is_sorted(t_stack *stack_a)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = stack_a->top;
	if (stack_a->top == NULL)
		return (0);
	while (i < stack_a->length - 1)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
		i++;
	}
	return (1);
}

int	stack_b_is_empty(t_stack *stack_b)
{
	if (stack_b->top == NULL)
		return (1);
	return (0);
}

int	check_if_sorted(t_stack *stack_a, t_stack *stack_b, char *instr)
{
	int		length;

	length = ft_strlen(instr);
	free(instr);
	if (length > 0)
		return (put_error(1));
	if (stack_a_is_sorted(stack_a) && stack_b_is_empty(stack_b))
	{
		write(1, "OK\n", 3);
		return (0);
	}
	write(1, "KO\n", 3);
	return (-1);
}
