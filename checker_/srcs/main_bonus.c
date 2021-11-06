/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:16:41 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/11/06 11:58:29 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	check_if_sorted(t_stack *stack_a, t_stack *stack_b, char *instr)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = stack_a->top;
	if (ft_strlen(instr) > 0)
	{
		free(instr);
		return (put_error(1));
	}
	free(instr);
	while (i < stack_a->length - 1)
	{
		if (temp->data > temp->next->data)
			return (put_error(3));
		temp = temp->next;
		i++;
	}
	write(1, "OK\n", 3);
	return (0);
}

int	read_perform_instuctions(t_stack *stack_a, t_stack *stack_b)
{
	char	*instr;
	int		ret;

	ret = get_next_line(0, &instr);
	while (ret == 1)
	{
		check_and_perform_instr(stack_a, stack_b, instr);
		ret = get_next_line(0, &instr);
	}
	if (ret == 0)
		return (check_if_sorted(stack_a, stack_b, instr));
	if (ret == -1)
	{
		free(instr);
		return (put_error(2));
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		exit_status;
	int		ret;

	stack_a = create_empty_stack("a");
	stack_b = create_empty_stack("b");
	if (stack_a == NULL || stack_b == NULL)
		return (free_memory(stack_a, stack_b, put_error(2)));
	/*
	 * this function return:
	 * ret == -1 if fail (Error[duplicate, non integer], allocation fail) + error printed
	 * ret == 0 if success (if stack no sorted)
	 * ret == 1 if success (if stack empty)
	 */
	ret = parsing(stack_a, argc, argv);
	if (ret == 0)
		ret = read_perform_instuctions(stack_a, stack_b);// return -1{fail<gnl>} or 0{success}
	exit_status = free_memory(stack_a, stack_b, ret);
	return (exit_status);
}
