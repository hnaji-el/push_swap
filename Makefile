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

NAME_PS = push_swap

NAME_CHECKER = checker

SRCS_PS = ./push_swap_/srcs/main.c \
		./push_swap_/srcs/push_swap_operations1.c \
		./push_swap_/srcs/push_swap_operations2.c \
		./push_swap_/srcs/stack_operations.c \
		./push_swap_/srcs/counting_sort.c \
		./push_swap_/srcs/counting_sort_utils.c \
		./push_swap_/srcs/parsing.c \
		./push_swap_/srcs/sort_big_stack.c \
		./push_swap_/srcs/sort_small_stack.c \
		./push_swap_/srcs/sort_small_stack_utils.c \
		./push_swap_/srcs/insertion_sort.c \
		./push_swap_/srcs/free_memory.c

SRCS_CHECKER = ./push_swap_/srcs/main.c \
		./push_swap_/srcs/push_swap_operations1.c \
		./push_swap_/srcs/push_swap_operations2.c \
		./push_swap_/srcs/stack_operations.c \
		./push_swap_/srcs/counting_sort.c \
		./push_swap_/srcs/counting_sort_utils.c \
		./push_swap_/srcs/parsing.c \
		./push_swap_/srcs/sort_big_stack.c \
		./push_swap_/srcs/sort_small_stack.c \
		./push_swap_/srcs/sort_small_stack_utils.c \
		./push_swap_/srcs/insertion_sort.c \
		./push_swap_/srcs/free_memory.c

INCLUDES_PS = ./push_swap_/includes/push_swap.h \
			./push_swap_/includes/stack.h \
			./push_swap_/includes/counting_sort.h

INCLUDES_CHECKER = ./push_swap_/includes/push_swap.h \
			./push_swap_/includes/stack.h \
			./push_swap_/includes/counting_sort.h

LIBFT = ./libft/libft.a

FLAGS = -Wall -Wextra -Werror

all: libft $(NAME_PS)

$(NAME_PS): $(SRCS_PS) $(INCLUDES_PS) $(LIBFT)
	@gcc $(FLAGS) $(SRCS_PS) $(LIBFT) -o $(NAME_PS) 

bonus: libft $(NAME_CHECKER)

$(NAME_CHECKER): $(SRCS_CHECKER) $(INCLUDES_CHECKER) $(LIBFT)
	@gcc $(FLAGS) $(SRCS_CHECKER) $(LIBFT) -o $(NAME_CHECKER) 

libft:
	@make -C ./libft

clean:
	@make -C ./libft clean

fclean:
	@make -C ./libft fclean
	@rm -rf $(NAME_PS)
	@rm -rf $(NAME_CHECKER)

re: fclean all

.PHONY: all clean fclean re bonus libft
