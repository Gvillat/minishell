# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvillat <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 12:31:10 by gvillat           #+#    #+#              #
#    Updated: 2016/06/06 16:56:24 by gvillat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIBFT = ft_isascii.c \
		ft_lstdel.c \
		ft_memccpy.c\
		ft_power.c\
		ft_putnbr_fd.c\
		ft_strcpy.c\
		ft_strlcat.c\
		ft_strncpy.c\
		ft_strsub.c\
		ft_wstrtostr.c\
		ft_atoi.c\
		ft_isdigit.c\
		ft_lstdelone.c\
		ft_memchr.c\
		ft_pushchar.c\
		ft_putstr.c\
		ft_strdel.c\
		ft_strlen.c\
		ft_strnequ.c\
		ft_strtrim.c\
		get_next_line.c\
		ft_bzero.c\
		ft_isescaped.c\
		ft_lstiter.c\
		ft_memcmp.c\
		ft_putchar.c\
		ft_putstr_fd.c\
		ft_strdup.c\
		ft_strlower.c\
		ft_strnew.c\
		ft_tolower.c\
		ft_countwords.c\
		ft_isprint.c\
		ft_lstmap.c\
		ft_memcpy.c\
		ft_putchar_fd.c\
		ft_strcat.c\
		ft_strequ.c\
		ft_strmap.c\
		ft_strnstr.c\
		ft_toupper.c\
		ft_decade.c\
		ft_itoa.c\
		ft_lstnew.c\
		ft_memdel.c\
		ft_putendl.c\
		ft_strchr.c\
		ft_striter.c\
		ft_strmapi.c\
		ft_strrchr.c\
		ft_wcharlen.c\
		ft_isalnum.c\
		ft_itoa_base.c\
		ft_lstpush.c\
		ft_memmove.c\
		ft_putendl_fd.c\
		ft_strclr.c\
		ft_striteri.c\
		ft_strncat.c\
		ft_strsplit.c\
		ft_wchartostr.c\
		ft_isalpha.c\
		ft_lstadd.c\
		ft_memalloc.c\
		ft_memset.c\
		ft_putnbr.c\
		ft_strcmp.c\
		ft_strjoin.c\
		ft_strncmp.c\
		ft_strstr.c\
		ft_wstrlen.c \
		fpf_char_conv.c \
		fpf_display.c \
		fpf_flags.c \
		fpf_memory.c \
		fpf_nputchar.c \
		fpf_printf.c \
		fpf_ptr_conv.c \
		fpf_signed_conv.c \
		fpf_str_conv.c \
		fpf_unsigned_conv.c \
		fpf_wildcard.c \

OBJ = $(LIBFT:.c=.o)

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -c $(LIBFT)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

norme:
	@norminette */*[hc]

.PHONY: re norme fclean clean all
