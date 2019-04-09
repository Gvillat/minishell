# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guvillat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/28 20:50:29 by guvillat          #+#    #+#              #
#    Updated: 2019/01/28 20:50:36 by guvillat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = clang

CFLAGS = -Wall -Wextra -Werror
LIBSRC = 	libft/ft_itoa_base.c \
			libft/ft_memset.c \
			libft/ft_nputchar.c \
			libft/ft_wstrtostr.c \
			libft/ft_wchartostr.c \
			libft/ft_wstrlen.c \
			libft/ft_wcharlen.c \
			libft/ft_isascii.c \
			libft/ft_lstdel.c \
			libft/ft_memccpy.c\
			libft/ft_power.c\
			libft/ft_putnbr_fd.c\
			libft/ft_strcpy.c\
			libft/ft_strlcat.c\
			libft/ft_strncpy.c\
			libft/ft_strsub.c\
			libft/ft_atoi.c\
			libft/ft_isdigit.c\
			libft/ft_lstdelone.c\
			libft/ft_memchr.c\
			libft/ft_pushchar.c\
			libft/ft_putstr.c\
			libft/ft_strdel.c\
			libft/ft_strlen.c\
			libft/ft_strnequ.c\
			libft/ft_strtrim.c\
			libft/ft_bzero.c\
			libft/ft_isescaped.c\
			libft/ft_lstiter.c\
			libft/ft_memcmp.c\
			libft/ft_putchar.c\
			libft/ft_putstr_fd.c\
			libft/ft_strdup.c\
			libft/ft_strlower.c\
			libft/ft_strnew.c\
			libft/ft_tolower.c\
			libft/ft_countwords.c\
			libft/ft_isprint.c\
			libft/ft_lstmap.c\
			libft/ft_memcpy.c\
			libft/ft_putchar_fd.c\
			libft/ft_strcat.c\
			libft/ft_strequ.c\
			libft/ft_strmap.c\
			libft/ft_strnstr.c\
			libft/ft_toupper.c\
			libft/ft_decade.c\
			libft/ft_itoa.c\
			libft/ft_lstnew.c\
			libft/ft_memdel.c\
			libft/ft_putendl.c\
			libft/ft_strchr.c\
			libft/ft_striter.c\
			libft/ft_strmapi.c\
			libft/ft_strrchr.c\
			libft/ft_isalnum.c\
			libft/ft_lstpush.c\
			libft/ft_memmove.c\
			libft/ft_putendl_fd.c\
			libft/ft_strclr.c\
			libft/ft_striteri.c\
			libft/ft_strncat.c\
			libft/ft_strsplit.c\
			libft/ft_isalpha.c\
			libft/ft_lstadd.c\
			libft/ft_memalloc.c\
			libft/ft_putnbr.c\
			libft/ft_strcmp.c\
			libft/ft_strjoin.c\
			libft/ft_strncmp.c\
			libft/ft_strstr.c\
			libft/ft_print_memory.c\
			libft/ft_putnbr_base.c\
			libft/ft_swap.c\
			libft/get_next_line.c\

SRC =	source/ft_printf.c\
		source/ft_flags.c\
		source/ft_memory.c\
		source/ft_char_conv.c\
		source/ft_float_conv.c\
		source/ft_str_conv.c\
		source/ft_signed_conv.c\
		source/ft_unsigned_conv.c\
		$(LIBSRC)\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rus $@ $^

%.o:%.c
	$(CC) $(CFLAGS) -c -I includes/ -o $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
