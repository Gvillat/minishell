/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_ptr_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:13:03 by gvillat           #+#    #+#             */
/*   Updated: 2017/05/22 16:13:05 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fpf_printf.h"

int		fpf_pointer_handler(PF *argument, va_list ap)
{
	uintmax_t	n;

	n = va_arg(ap, uintmax_t);
	if (!(argument->arg = ft_strlower(ft_itoa_base(n, 16))))
		return (-1);
	return (fpf_print_number(argument, "0x"));
}

int		fpf_prc_handle(PF *argument, va_list ap)
{
	argument->arg = "%";
	fpf_print_character(argument);
	return ((int)ap);
}
