/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:24:16 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/11/06 19:38:55 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*create_empty_stack(char *name)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->top = (void *)0;
	stack->name = name;
	stack->length = 0;
	return (stack);
}

t_node	*get_new_node(int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->data = data;
	node->index = 0;
	node->next = (void *)0;
	node->prev = (void *)0;
	return (node);
}

int	push(int data, t_stack *stack)
{
	t_node	*node;

	node = get_new_node(data);
	if (node == NULL)
		return (-1);
	stack->length += 1;
	if (stack->top == NULL)
	{
		node->next = node;
		node->prev = node;
		stack->top = node;
		return (0);
	}
	node->next = stack->top;
	node->prev = stack->top->prev;
	stack->top->prev->next = node;
	stack->top->prev = node;
	stack->top = node;
	return (0);
}

void	pop(t_stack *stack)
{
	t_node	*temp;

	if (stack->top == NULL)
		return ;
	stack->length -= 1;
	if (stack->top == stack->top->next)
	{
		free(stack->top);
		stack->top = NULL;
		return ;
	}
	temp = stack->top;
	stack->top->prev->next = stack->top->next;
	stack->top->next->prev = stack->top->prev;
	stack->top = stack->top->next;
	free(temp);
}

int	top(t_stack *stack)
{
	return (stack->top->data);
}
