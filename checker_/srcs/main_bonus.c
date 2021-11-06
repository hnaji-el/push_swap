/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:16:41 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/11/06 15:48:47 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	read_perform_instuctions(t_stack *stack_a, t_stack *stack_b)
{
	char	*instr;
	int		ret;

	ret = get_next_line(0, &instr);
	while (ret == 1)
	{
		if (check_and_perform_instr(stack_a, stack_b, instr) == -1)
			return (-1);
		ret = get_next_line(0, &instr);
	}
	if (ret == 0)
		return (check_if_sorted(stack_a, stack_b, instr));
	free(instr);
	return (put_error(3));
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
	ret = parsing(stack_a, argc, argv);
	if (ret == 0)
		ret = read_perform_instuctions(stack_a, stack_b);
	exit_status = free_memory(stack_a, stack_b, ret);
	return (exit_status);
}
