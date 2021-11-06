/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:16:41 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/11/06 19:31:07 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	{
		if (stack_a->length <= 5)
			ret = sort_small_stack(stack_a, stack_b);
		else
			ret = sort_big_stack(stack_a, stack_b);
	}
	exit_status = free_memory(stack_a, stack_b, ret);
	return (exit_status);
}
