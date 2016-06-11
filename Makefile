# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oexall <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/06 10:47:52 by oexall            #+#    #+#              #
#    Updated: 2016/06/11 09:27:06 by oexall           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = ft_ls.c error.c process_args.c core.c utils.c stats.c display_files.c \
	  ft_substring.c \
	  ./ListUtils/ft_create_elem.c \
	  ./ListUtils/ft_list_push_back.c \
	  ./ListUtils/ft_list_push_front.c \
	  ./ListUtils/ft_clear_list.c \
	  ./ListUtils/ft_create_special.c \
	  ./ListUtils/ft_list_push_back_special.c \
	  ./ListUtils/ft_list_reverse.c sort.c
OBJ = $(SRC:.c=.o)
CC = clang -g -o
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

clean:
	@rm -f ft_ls
	@echo "Removed Executable"

fclean: clean
	@make -C libft/ fclean
	@echo "Finished Full Clean"

re: fclean all
