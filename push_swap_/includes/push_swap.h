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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

/*      include stack.h and counting_sort.h		 */
# include "stack.h"
# include "counting_sort.h"

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

void	insertion_sort(int *arr, int n);
int		adjust_min_pos(t_stack *stack_a, int min_pos);
int		get_min_pos(t_stack *stack);

/*            sort_small_stack.c                 */
int		sort_small_stack(t_stack *stack_a, t_stack *stack_b);
void	sort_stack_3(t_stack *stack);
int		sort_stack_4(t_stack *stack_a, t_stack *stack_b);
int		sort_stack_5(t_stack *stack_a, t_stack *stack_b);

/*            sort_big_stack.c                   */
int		sort_big_stack(t_stack *stack_a, t_stack *stack_b);

/*                parsing.c                      */
int		parsing(t_stack *stack, int argc, char **argv);

/*                free_memory.c                      */
int		free_memory(t_stack *stack_a, t_stack *stack_b, int ret);
int		put_error(int arrnum);

/*           push_swap_operations1.c             */
void	swap_on_two_stack(t_stack *stack_a, t_stack *stack_b);
void	rotate_on_two_stack(t_stack *stack_a, t_stack *stack_b);
void	rev_rotate_on_two_stack(t_stack *stack_a, t_stack *stack_b);

/*             push_swap_operations2.c           */
void	swap(t_stack *stack, int print);
int		push_(t_stack *stack_1, t_stack *stack_2);
void	rotate(t_stack *stack, int print);
void	reverse_rotate(t_stack *stack, int print);
void	print_operation(char *prefix, char *suffix);

#endif
