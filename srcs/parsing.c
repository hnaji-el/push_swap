/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 07:59:12 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/11/04 11:34:33 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_is_sorted(t_stack *stack)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = stack->top;
	if (stack->top == NULL)
		return (1);
	while (i < stack->length - 1)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
		i++;
	}
	return (1);
}

int	data_is_duplicate(t_stack *stack, int data)
{
	t_node	*temp;

	temp = stack->top;
	if (stack->top == NULL)
		return (0);
	while (1)
	{
		if (temp->data == data)
			return (1);
		temp = temp->next;
		if (temp == stack->top)
			break;
	}
	return (0);
}

int	parsing(t_stack *stack, int argc, char **argv)
{
	long	data;

	while (argc-- > 1)
	{
		data = ft_atoi_plus_l(&argv[argc]);
		if (*argv[argc] != '\0' || data < INT_MIN || data > INT_MAX
			|| data_is_duplicate(stack, data))
			return (put_error(1));
		if (push(data, stack) == -1)
			return (put_error(2));
	}
	return (stack_is_sorted(stack));
}
