/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:16:41 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/10/18 12:29:47 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/stack.h"

void	check_errors_and_fill_stack_a(t_stack *stack_a, int argc, char **argv)
{
	int		data;

	while (argc-- > 1)
	{
		data = ft_atoi_plus_l(&argv[argc]);
		if (*argv[argc] != '\0' || data < INT_MIN || data > INT_MAX)
		{
			printf("Error\n");
			exit(1);
		}
		push(data, stack_a);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = create_empty_stack("a");
	stack_b = create_empty_stack("b");
	check_errors_and_fill_stack_a(stack_a, argc, argv);
	printf("-------stack_a-------\n"); 
	print_stack(stack_a);
	printf("---------------------\n");
//	printf("-------stack_b-------\n"); 
//	print_stack(stack_b);
//	printf("---------------------\n");
	return (0);
}
