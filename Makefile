# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 09:44:01 by hnaji-el          #+#    #+#              #
#    Updated: 2021/10/06 12:23:14 by hnaji-el         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# OUTPUT: compile the project
# CONTENT: usual rules (all, $(NAME), clean, fclean, re)
# can only RECOMPILE the program if necessary

NAME = push_swap

SRCS = ./srcs/push_swap.c

INCLUDES = ./includes/push_swap.h

LIBFT = ./libft/libft.a

FLAGS = -Wall -Wextra -Werror

all: libft $(NAME)

$(NAME): $(SRCS) $(INCLUDES)
	@gcc $(FLAGS) $(SRCS) $(LIBFT) -o $(NAME) 

clean:
	@make -C ./libft clean

fclean:
	@make -C ./libft fclean
	@rm -rf $(NAME)

re: fclean all

libft:
	@make -C ./libft 

.PHONY: all clean fclean re libft
