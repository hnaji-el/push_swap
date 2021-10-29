# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 09:44:01 by hnaji-el          #+#    #+#              #
#    Updated: 2021/10/18 12:27:58 by hnaji-el         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# OUTPUT: compile the project
# CONTENT: usual rules (all, $(NAME), clean, fclean, re)
# can only RECOMPILE the program if necessary (in the case : change anything in sources <push_swap> or <libft>)

NAME = push_swap

SRCS = ./srcs/push_swap.c \
		./srcs/push_swap_operations.c \
		./srcs/stack_operations.c

INCLUDES = ./includes/push_swap.h \
			./includes/stack.h

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
