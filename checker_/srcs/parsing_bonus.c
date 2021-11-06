/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 07:59:12 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/11/06 11:51:09 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

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

int	get_number_of_digits(char *str)
{
	int		i;
	int		num_digit;

	i = 0;
	num_digit = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
		if (str[i] == '\0')
			return (11);
	}
	while (ft_isdigit(str[i]))
	{
		i++;
		num_digit++;
	}
	return (num_digit);
}

int	parsing(t_stack *stack, int argc, char **argv)
{
	long	data;

	if (argc == 1)
		return (1);
	while (argc-- > 1)
	{
		if (get_number_of_digits(argv[argc]) > 10)
			return (put_error(1));
		data = ft_atoi_plus_l(&argv[argc]);
		if (*argv[argc] != '\0' || data < INT_MIN || data > INT_MAX
			|| data_is_duplicate(stack, data))
			return (put_error(1));
		if (push(data, stack) == -1)
			return (put_error(2));
	}
	return (0);
}
