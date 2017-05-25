/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_printf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:05:57 by gvillat           #+#    #+#             */
/*   Updated: 2017/05/22 16:06:13 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FPF_PRINTF_H
# define FPF_PRINTF_H
# define PF t_printf
# define SPE t_spec
# define BUFF_MAX 58
# define FD 1
# include <stdarg.h>
# include <wchar.h>
# include "libft.h"

char	g_buff[BUFF_MAX];
int		g_i;

/*
** fla[13] is an array which contains flags for precision, width, flags
** and modifiers such as:
** |0        |1    |2|3|4|5|6|7 |8|9 |10|11|12|
** |precision|width|#|0|-|+| |hh|h|ll|l |j |z |
** %[flags][width][.precision][length]specifier
** specifier : s S p d D i o O u U x X c C b
*/

typedef struct s_printf	t_printf;
typedef struct s_spec	t_spec;

struct	s_printf
{
	char			*format;
	size_t			index;
	unsigned char	spec;
	int				flags[13];
	char			*arg;
	wchar_t			*warg;
	int				ret;
};

struct	s_spec
{
	int (*spe[128])(PF*, va_list);
};

int		fpf_printf(const char *format, ...);

/*
** DISPLAY
*/

void	fpf_display(PF *argument);
void	*fpf_buff(char *str, PF *argument);
void	fpf_buf(char c, PF *argument);
int		fpf_print_character(PF *argument);
int		fpf_print_str(PF *argument);
int		fpf_print_number(PF *argument, char *pre);

/*
** MEMORY
*/

void	fpf_free(PF *argument);
void	fpf_init_buff();
PF		*fpf_init_argument(PF *argument);
void	fpf_init_spe_tab(SPE *spe);

/*
** LIBPRINTF
*/

void	fpf_nputchar(char c, ssize_t n, PF *argument);

/*
** HANDLER
*/

int		fpf_signed_handler(PF *argument, va_list ap);
int		fpf_pointer_handler(PF *argument, va_list ap);
int		fpf_character_handler(PF *argument, va_list ap);
int		fpf_string_handler(PF *argument, va_list ap);
int		fpf_unsigned_handler(PF *argument, va_list ap);
int		fpf_arg_nospe(PF *argument, va_list ap);
int		fpf_prc_handle(PF *argument, va_list ap);

/*
** FLAGS
*/

int		fpf_wildcard(PF *argument, va_list ap, int index);
int		fpf_get_flags(PF *argu, va_list ap);
int		fpf_check_flags(PF *argu);
int		fpf_check_width(PF *argu, va_list ap);
int		fpf_check_precision(PF *argument, va_list ap);
void	fpf_check_length(PF *argu);
int		fpf_check_spec(PF *argument);
int		fpf_check_spec_bis(PF *argument);

#endif
