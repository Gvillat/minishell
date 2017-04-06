NAME = minishell

SRC = main.c init_env.c get_next_line.c del_hash.c \
	print_error.c exec_path.c exec_cmd.c exec_file.c exec_builtin.c bi_exit.c \
	bi_cd.c bi_env.c bi_setenv.c bi_unsetenv.c bi_setprompt.c build_env_tab.c \
	parse_vars.c

INCLUDES = -Iincludes -Ilibft/includes -Ilibhash/includes
LIB_FLAGS = -Llibft -lft -Llibhash -lhash
FLAGS = -Wextra -Werror -Wall $(INCLUDES)

OBJ_DIR = obj
SRC_DIR = src

VPATH = $(SRC_DIR)

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@make -C libft
	@make -C libhash
	@gcc -Ofast $(OBJS) $(FLAGS) $(LIB_FLAGS) -o $(NAME)
	@echo "\n✅  MINISHELL BUILT !"

$(OBJ_DIR):
	@mkdir  $@

$(OBJ_DIR)/%.o: %.c
	@gcc $(FLAGS) -c $< -o $@
	@echo "$(NAME) => \033[33;32m$@\033[33;0m"

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	@make -C libft fclean
	@make -C libhash fclean

re: fclean all
