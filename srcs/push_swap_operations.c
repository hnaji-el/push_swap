
#include "../includes/push_swap.h"
#include "../includes/stack.h"

void	print_operation(char *prefix, char *suffix)
{
	ft_putstr(prefix);
	ft_putstr(suffix);
	write(1, "\n", 1);
}

void	swap(t_stack *stack, int print)
{
	int		temp;

	if (stack->length < 2)
		return ;
	temp = stack->top->data;
	stack->top->data = stack->top->next->data;
	stack->top->next->data = temp;
	if (print == 1)
		print_operation("s", stack->name);
}

void	push_(t_stack *stack_1, t_stack *stack_2)
{
	int		data;

	if (stack_2->length == 0)
		return ;
	data = top(stack_2);
	pop(stack_2);
	push(data, stack_1);
	print_operation("p", stack_1->name);
}

void	rotate(t_stack *stack, int print)
{
	if (stack->length < 2)
		return ;
	stack->top = stack->top->next;
	if (print == 1)
		print_operation("r", stack->name);
}

void	reverse_rotate(t_stack *stack, int print)
{
	if (stack->length < 2)
		return ;
	stack->top = stack->top->prev;
	if (print == 1)
		print_operation("rr", stack->name);
}

void	swap_on_two_stack(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a, 0);
	swap(stack_b, 0);
	if (stack_a->length > 1 || stack_b->length > 1)
		write(1, "ss\n", 3);
}

void	rotate_on_two_stack(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	if (stack_a->length > 1 || stack_b->length > 1)
		write(1, "rr\n", 3);
}

void	rev_rotate_on_two_stack(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a, 0);
	reverse_rotate(stack_b, 0);
	if (stack_a->length > 1 || stack_b->length > 1)
		write(1, "rrr\n", 4);
}
