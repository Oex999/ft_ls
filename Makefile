# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oexall <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/06 10:47:52 by oexall            #+#    #+#              #
#    Updated: 2016/06/06 14:38:43 by oexall           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = ft_ls.c error.c process_args.c core.c
OBJ = $(SRC:.c=.o)
CC = gcc -o
CFLAGS = -Wall -Werror -Wextra
LIBFT = -L ./libft/ -lft

all: $(NAME)

$(NAME):
	@clear
	@echo "Compiling libft..."
	@make -C ./libft/ fclean
	@make -C ./libft/
	@echo "Compiled libft"
	@$(CC) $(NAME) $(CFLAGS) $(SRC) $(LIBFT)
	@echo "compiled ft_ls."

quick:
	@clear
	@$(CC) $(NAME) $(CFLAGS) $(SRC) $(LIBFT)
	@echo "compiled ft_ls."
