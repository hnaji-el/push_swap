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

int	counting_sort(int *arr, int n);

void	fill_index_in_node(t_node *node, int *array, int size_array)
{
	int		i;

	i = 0;
	while (i < size_array)
	{
		if (node->data == array[i])
		{
			node->index = i;
			break ;
		}
		i++;
	}
}

void	copy_stack_into_array(t_stack *stack, int *array)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = stack->top;
	while (i < stack->length)
	{
		array[i] = temp->data;
		temp = temp->next;
		i++;
	}
}

int	fill_indeces_in_stack_a(t_stack *stack_a)
{
	int		*auxill_arr;
	t_node	*temp;

	temp = stack_a->top;
	auxill_arr = (int *)malloc(sizeof(int) * stack_a->length);
	if (auxill_arr == NULL)
		return (-1);
	copy_stack_into_array(stack_a, auxill_arr);
	counting_sort(auxill_arr, stack_a->length);
	while (1)
	{
		fill_index_in_node(temp, auxill_arr, stack_a->length);
		temp = temp->next;
		if (temp == stack_a->top)
			break ;
	}
	free(auxill_arr);
	return (0);
}

void	sort_big_stack(t_stack *stack_a, t_stack *stack_b)
{
	int		max;
	int		length;
	int		i;
	int		j;

	i = 0;
	length = stack_a->length;
	max = stack_a->length - 1;
	fill_indeces_in_stack_a(stack_a); // return -1 {failure} or 0 {success}
	while ((max >> i) != 0)
	{
		j = 0;
		while (j < length)
		{
			if ((stack_a->top->index & (1 << i)) == 0)
				push_(stack_b, stack_a);
			else
				rotate(stack_a, 1);
			j++;
		}
		while (stack_b->length > 0)
			push_(stack_a, stack_b);
		i++;
	}
}

int	stack_is_sorted(t_stack *stack)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = stack->top;
	if (stack->top == NULL)
		return (1);
	while (i < stack->length - 1)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
		i++;
	}
	return (1);
}

int	data_is_duplicate(t_stack *stack, int data)
{
	t_node	*temp;

	temp = stack->top;
	if (stack->top == NULL)
		return (0);
	while (1)
	{
		if (temp->data == data)
			return (1);
		temp = temp->next;
		if (temp == stack->top)
			break;
	}
	return (0);
}

int	check_errors_and_fill_stack(t_stack *stack, int argc, char **argv)
{
	long	data;

	while (argc-- > 1)
	{
		data = ft_atoi_plus_l(&argv[argc]);
		if (*argv[argc] != '\0' || data < INT_MIN || data > INT_MAX
			|| data_is_duplicate(stack, data))
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		push(data, stack);
	}
	return (stack_is_sorted(stack));
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		ret;

	stack_a = create_empty_stack("a"); // protect this
	stack_b = create_empty_stack("b"); // protect this
	/*
	 * this function return:
	 * ret == -1 if fail (Error[duplicate, non integer])
	 * ret == 0 if success (if stack no sorted)
	 * ret == 1 if success (if stack sorted or empty)
	 */
	ret = check_errors_and_fill_stack(stack_a, argc, argv);
	if (ret == 0)
	{
//		if (stack_a->length <= 5)
//			sort_small_stack(stack_a, stack_b);
//		else
		sort_big_stack(stack_a, stack_b);
	}
	/*
	 * free memory in this stage
	 */
	return (0);
}

//	if (flag == 0 && stack_a->length != 0)
//	{
//		printf("-------stack_a-------\n"); 
//		print_stack(stack_a);
//		printf("---------------------\n");
//	}
