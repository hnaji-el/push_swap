# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 09:44:01 by hnaji-el          #+#    #+#              #
#    Updated: 2021/11/04 12:17:17 by hnaji-el         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# OUTPUT: compile the project
# CONTENT: usual rules (all, $(NAME), clean, fclean, re)
# can only RECOMPILE the program if necessary (in the case : change anything in sources <push_swap> or <libft>)

NAME = push_swap

SRCS = ./srcs/push_swap.c \
		./srcs/push_swap_operations1.c \
		./srcs/push_swap_operations2.c \
		./srcs/stack_operations.c \
		./srcs/counting_sort.c \
		./srcs/counting_sort_utils.c \
		./srcs/parsing.c \
		./srcs/sort_big_stack.c \
		./srcs/sort_small_stack.c \
		./srcs/sort_small_stack_utils.c \
		./srcs/insertion_sort.c \
		./srcs/free_memory.c

INCLUDES = ./includes/push_swap.h \
			./includes/stack.h \
			./includes/counting_sort.h

LIBFT = ./libft/libft.a

FLAGS = -Wall -Wextra -Werror

all: libft $(NAME)

$(NAME): $(SRCS) $(INCLUDES) $(LIBFT)
	@gcc $(FLAGS) $(SRCS) $(LIBFT) -o $(NAME) 

libft:
	@make -C ./libft

clean:
	@make -C ./libft clean

fclean:
	@make -C ./libft fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
