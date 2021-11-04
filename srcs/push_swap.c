/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:16:41 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/11/04 13:19:49 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		ret;

	stack_a = create_empty_stack("a");
	stack_b = create_empty_stack("b");
	if (stack_a == NULL || stack_b == NULL)
		return (free_memory(stack_a, stack_b, put_error(2)));
	/*
	 * this function return:
	 * ret == -1 if fail (Error[duplicate, non integer], allocation fail)
	 * ret == 0 if success (if stack no sorted)
	 * ret == 1 if success (if stack sorted or empty)
	 */
	ret = parsing(stack_a, argc, argv);
	if (ret == 0)
	{
		if (stack_a->length <= 5)
			ret = sort_small_stack(stack_a, stack_b);
		else
			ret = sort_big_stack(stack_a, stack_b);
	}
	return (free_memory(stack_a, stack_b, ret));
}
