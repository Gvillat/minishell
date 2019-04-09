# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guvillat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/01 13:14:43 by guvillat          #+#    #+#              #
#    Updated: 2019/04/01 13:14:45 by guvillat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re norme

CC = gcc

FLAGS = -Wall -Wextra -Werror 
NAME = minishell

SRC_PATH = ./sources
OBJ_PATH = ./.obj

SRC_NAME =	builtins.c\
			cd_build_free.c\
			lst.c\
			main.c\
			parse_and_exec.c\
			run.c\

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(SRC)
	@cd ./lib && $(MAKE) 
	@$(CC) $(FLAGS) -o $@ $^ ./lib/libftprintf.a
	@echo "\033[1;34mminishell\t\t\033[1;33mCompilation\t\033[0;32m-OK-\033[0m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ)
	@cd ./lib/ && $(MAKE) clean
	@echo "\033[1;34mminishell\t\033[1;33mCleaning obj\t\033[0;32m-OK-\033[0m"

fclean: clean
	@rm -rf ./.obj $(NAME)
	@rm -rf ./lib/libftprintf.a
	@cd ./lib && $(MAKE) fclean
	@echo "\033[1;34mminishell\t\033[1;33mCleaning lib\t\033[0;32m-OK-\033[0m"
	
re: fclean all
