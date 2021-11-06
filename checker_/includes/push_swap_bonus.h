/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:25:32 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/11/06 16:03:18 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# define BUFFER_SIZE 1
# define INT_MAX 2147483647
# define INT_MIN -2147483648

/*            include stack_bonus.h       		 */
# include "stack_bonus.h"

/*         include my own library <libft>        */
# include "../../libft/libft.h"

/*          write() and read() functions         */
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

/*     malloc(), free() and exit() functions     */
# include <stdlib.h>

/*               check_sorted_bonus.c                  */
int		check_if_sorted(t_stack *stack_a, t_stack *stack_b, char *instr);

/*                free_memory_bonus.c                      */
int		free_memory(t_stack *stack_a, t_stack *stack_b, int ret);
int		put_error(int errnum);

/*                gnl_bonus.c                  */
int		get_next_line(int fd, char **line);

/*                parsing.c                      */
int		parsing(t_stack *stack, int argc, char **argv);
int		data_is_duplicate(t_stack *stack, int data);

/*                perform_instrs_bonus.c                  */
int		check_and_perform_instr(t_stack *stack_a, t_stack *stack_b,
			char *instr);
/*             push_swap_operations1_bonus.c           */
void	swap(t_stack *stack);
int		push_(t_stack *stack_1, t_stack *stack_2);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

/*           push_swap_operations2_bonus.c             */
void	swap_on_two_stack(t_stack *stack_a, t_stack *stack_b);
void	rotate_on_two_stack(t_stack *stack_a, t_stack *stack_b);
void	rev_rotate_on_two_stack(t_stack *stack_a, t_stack *stack_b);

#endif
