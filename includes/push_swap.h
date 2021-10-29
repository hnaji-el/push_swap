/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:25:32 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/10/06 10:37:37 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

/*             my own library <libft>            */
# include "../libft/libft.h"

/*       printf() function is not ALLOWED        */
/*                  ATTENTION                    */
# include <stdio.h>

/*          write() and read() functions         */
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

/*     malloc(), free() and exit() functions     */
# include <stdlib.h>

/*		       include stack.h 					 */
# include "stack.h"

void	swap(t_stack *stack, int print);
void	push_(t_stack *stack_1, t_stack *stack_2);
void	rotate(t_stack *stack, int print);
void	reverse_rotate(t_stack *stack, int print);

void	swap_on_two_stack(t_stack *stack_a, t_stack *stack_b);
void	rotate_on_two_stack(t_stack *stack_a, t_stack *stack_b);
void	rev_rotate_on_two_stack(t_stack *stack_a, t_stack *stack_b);

void	print_operation(char *prefix, char *suffix);

#endif
