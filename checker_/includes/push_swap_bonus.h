/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:25:32 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/11/04 12:19:53 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct	s_node
{
	char			*data;
	struct s_node	*next;
}				t_node;

/*      include stack.h and counting_sort.h		 */
# include "stack_bonus.h"

/*         include my own library <libft>        */
# include "../../libft/libft.h"

/*       printf() function is not ALLOWED        */
/*                  ATTENTION                    */
# include <stdio.h>
# include <stdbool.h>

/*          write() and read() functions         */
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

/*     malloc(), free() and exit() functions     */
# include <stdlib.h>

/*             push_swap_operations1_bonus.c           */
void	swap(t_stack *stack);
int		push_(t_stack *stack_1, t_stack *stack_2);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

/*           push_swap_operations2_bonus.c             */
void	swap_on_two_stack(t_stack *stack_a, t_stack *stack_b);
void	rotate_on_two_stack(t_stack *stack_a, t_stack *stack_b);
void	rev_rotate_on_two_stack(t_stack *stack_a, t_stack *stack_b);

/*                free_memory_bonus.c                      */
int		free_memory(t_stack *stack_a, t_stack *stack_b, int ret);
int		put_error(int arrnum);

/*                parsing.c                      */
int		parsing(t_stack *stack, int argc, char **argv);
int	stack_is_sorted(t_stack *stack);
int	data_is_duplicate(t_stack *stack, int data);

/*                circular_ll_bonus.c                      */
t_node	*get_new_node(char *data);
int 	insert_at_end(char *data, t_node **tail);
void	delete_at_beg(t_node **tail);
int		strlen_list(t_node *tail);
void	print_list(t_node *tail);

#endif
