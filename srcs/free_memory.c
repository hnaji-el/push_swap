/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:45:51 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/11/04 12:19:18 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	put_error(int errnum)
{
	if (errnum == 1)
		write(2, "Error\n", 6);
	if (errnum == 2)
		write(2, "Error\nCannot allocate memory\n", 29);
	return (-1);
}

void	free_stack(t_stack *stack)
{
	if (stack == NULL)
		return ;
	while (stack->top != NULL)
		pop(stack);
	free(stack);
}

int	free_memory(t_stack *stack_a, t_stack *stack_b, int ret)
{
	free_stack(stack_a);
	free_stack(stack_b);
	if (ret == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
