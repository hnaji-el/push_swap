/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 08:06:49 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/11/06 16:04:47 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_BONUS_H
# define STACK_BONUS_H

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_stack
{
	t_node	*top;
	char	*name;
	int		length;
}				t_stack;

t_stack	*create_empty_stack(char *name);
int		push(int data, t_stack *stack);
void	pop(t_stack *stack);
int		top(t_stack *stack);

#endif
