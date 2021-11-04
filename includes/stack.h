
#ifndef STACK_H
# define STACK_H

typedef struct	s_node
{
	int				data;
	int				index;
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
int		isempty(t_stack *stack);
void	print_stack(t_stack *stack);

#endif
