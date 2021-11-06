/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_instrs_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:41:34 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/11/06 15:44:59 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	check_perform_s(t_stack *stack_a, t_stack *stack_b, char *instr)
{
	if (!ft_strcmp(instr, "sa"))
		swap(stack_a);
	else if (!ft_strcmp(instr, "sb"))
		swap(stack_b);
	else if (!ft_strcmp(instr, "ss"))
		swap_on_two_stack(stack_a, stack_b);
	else
		return (-1);
	return (0);
}

int	check_perform_p(t_stack *stack_a, t_stack *stack_b, char *instr)
{
	if (!ft_strcmp(instr, "pa"))
		push_(stack_a, stack_b);
	else if (!ft_strcmp(instr, "pb"))
		push_(stack_b, stack_a);
	else
		return (-1);
	return (0);
}

int	check_perform_rr(t_stack *stack_a, t_stack *stack_b, char *instr)
{
	if (!ft_strcmp(instr, "rr"))
		rotate_on_two_stack(stack_a, stack_b);
	else if (!ft_strcmp(instr, "rra"))
		reverse_rotate(stack_a);
	else if (!ft_strcmp(instr, "rrb"))
		reverse_rotate(stack_b);
	else if (!ft_strcmp(instr, "rrr"))
		rev_rotate_on_two_stack(stack_a, stack_b);
	else
		return (-1);
	return (0);
}

int	check_perform_r(t_stack *stack_a, t_stack *stack_b, char *instr)
{
	if (!ft_strcmp(instr, "ra"))
		rotate(stack_a);
	else if (!ft_strcmp(instr, "rb"))
		rotate(stack_b);
	else
		return (-1);
	return (0);
}

int	check_and_perform_instr(t_stack *stack_a, t_stack *stack_b, char *instr)
{
	int		ret;

	ret = -1;
	if (*instr == 's')
		ret = check_perform_s(stack_a, stack_b, instr);
	else if (*instr == 'p')
		ret = check_perform_p(stack_a, stack_b, instr);
	else if (!ft_strncmp(instr, "rr", 2))
		ret = check_perform_rr(stack_a, stack_b, instr);
	else if (*instr == 'r')
		ret = check_perform_r(stack_a, stack_b, instr);
	free(instr);
	if (ret == -1)
		return (put_error(1));
	return (0);
}
