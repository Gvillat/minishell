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

$(NAME):
	@make -C ./libft
	@$(CC) $(FLAGS) -o $(NAME) $(SRC) libft/libft.a
	@ranlib $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

norme:
	@norminette */*[hc]
