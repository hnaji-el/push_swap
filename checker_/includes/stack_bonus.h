/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 08:06:49 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/11/04 11:45:28 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_BONUS_H
# define STACK_BONUS_H

typedef struct	s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct	s_stack
{
	t_node	*top;
	char	*name;
	int		length;
}				t_stack;

t_stack	*create_empty_stack(char *name);// NULL(failure) or stack(success)
int		push(int data, t_stack *stack);// -1(failure) or 0(success) && s->length++
void	pop(t_stack *stack);// return void, if stack->top == NULL no operation performed, && s->length--
int		top(t_stack *stack);

#endif
