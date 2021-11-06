# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 09:44:01 by hnaji-el          #+#    #+#              #
#    Updated: 2021/11/06 20:33:00 by hnaji-el         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap

NAME_CHECKER = checker

SRCS_PS = ./push_swap_/srcs/main.c \
		  ./push_swap_/srcs/push_swap_operations1.c \
		  ./push_swap_/srcs/push_swap_operations2.c \
		  ./push_swap_/srcs/stack_operations.c \
		  ./push_swap_/srcs/parsing.c \
		  ./push_swap_/srcs/sort_big_stack.c \
		  ./push_swap_/srcs/sort_small_stack.c \
		  ./push_swap_/srcs/sort_small_stack_utils.c \
		  ./push_swap_/srcs/insertion_sort.c \
		  ./push_swap_/srcs/free_memory.c

SRCS_CHECKER = ./checker_/srcs/main_bonus.c \
			   ./checker_/srcs/gnl_bonus.c \
			   ./checker_/srcs/parsing_bonus.c \
			   ./checker_/srcs/push_swap_operations1_bonus.c \
			   ./checker_/srcs/push_swap_operations2_bonus.c \
			   ./checker_/srcs/stack_operations_bonus.c \
			   ./checker_/srcs/check_sorted_bonus.c \
			   ./checker_/srcs/perform_instrs_bonus.c \
			   ./checker_/srcs/free_memory_bonus.c

INCLUDES_PS = ./push_swap_/includes/push_swap.h \
			  ./push_swap_/includes/stack.h

INCLUDES_CHECKER = ./checker_/includes/push_swap_bonus.h \
				   ./checker_/includes/stack_bonus.h \

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
