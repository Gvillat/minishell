NAME = minishell

SRC = main.c  lst_new.c lst_push.c lst_iter.c lst_search.c lst_free.c \
	  print_env.c fill.c check_is_builtins.c read_entries.c free.c \
	  signal_handler.c try_entry.c exit_prog.c set_env.c  error.c\
	  unsetenv.c lst_del_one.c change_directory.c lst_change_value.c \
	  check_is_exec.c lst_get_value.c lst_to_tab.c lst_get_size.c \
	  check_is_variable.c chut.c

FLAGS =  -Werror -Wall -Wextra -Iincludes -Ilibft/includes -g

OBJ_DIR = objs
SRC_DIR = src

VPATH = $(SRC_DIR)

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@make -C libft
	@gcc  $(OBJS) $(FLAGS) -Llibft -lft -o $(NAME)
	@echo "ft_ls built !"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	@make -C libft clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all
	@make -C libft re
