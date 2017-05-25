# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvillat <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/22 15:53:57 by gvillat           #+#    #+#              #
#    Updated: 2017/05/22 15:53:59 by gvillat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean norme

NAME = minishell

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC =	sources/builtins.c \
		sources/lst.c \
		sources/cd_build_free.c \
		sources/main.c\
		sources/parse_and_exec.c \
		sources/run.c \

OBJ =	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	@$(CC) $(FLAGS) -o $(NAME) $(SRC) libft/libft.a

clean:
	rm -rf sources/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

norme:
	@norminette */*[hc]
