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

#include "../includes/push_swap_bonus.h"

char	*read_one_instruction(void)
{
	char	*buffer;
	char	*str;
	int		ret;

	buffer = (char *)malloc(sizeof(char));
	str = ft_strdup("");
	while (1)
	{
		ret = read(0, buffer, 1);
		if (ret == 0)
			break ;
		if (*buffer == '\n')
		{
			str = ft_strjoin(str, "\0");
		}
		str = ft_strjoin(str, buffer);
	}
}

int	perform_instuctions(t_stack *stack_a, t_stack *stack_b)
{
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
	{
		ret = read_instructions();
		ret = perform_instuctions(stack_a, stack_b);
	}
	exit_status = free_memory(stack_a, stack_b, ret);
	return (exit_status);
}
