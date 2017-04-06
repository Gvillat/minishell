NAME = libhash.a

SRC = hash_new.c hash_set.c hash_unset.c hash_get.c hash_count.c hash_del.c \
		hash_getset.c hash_delone.c hash_foreach.c

INCLUDES = -Iincludes -I../libft/includes
FLAGS = -Wextra -Werror -Wall $(INCLUDES)

OBJ_DIR = obj
SRC_DIR = src

VPATH = $(SRC_DIR)

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\n✅  LIBHASH BUILT !"

$(OBJ_DIR):
	@mkdir  $@

$(OBJ_DIR)/%.o: %.c
	@gcc $(FLAGS) -c $< -o $@
	@echo "$(NAME) => \033[33;32m$@\033[33;0m"

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	@make -C ../libft fclean

re: fclean all
