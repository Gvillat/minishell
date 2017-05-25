/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:12:20 by gvillat           #+#    #+#             */
/*   Updated: 2017/05/22 16:12:22 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fpf_printf.h"

PF		*fpf_init_argument(PF *argument)
{
	int i;

	i = 0;
	while (i < 13)
	{
		argument->flags[i] = 0;
		i++;
	}
	argument->flags[0] = -1;
	argument->flags[1] = -1;
	argument->format = NULL;
	argument->index = 0;
	argument->spec = ' ';
	argument->arg = NULL;
	argument->warg = NULL;
	return (argument);
}

void	fpf_init_spe_tab(SPE *spe)
{
	int i;

	i = 0;
	while (i < 128)
		spe->spe[i++] = fpf_arg_nospe;
	spe->spe['p'] = fpf_pointer_handler;
	spe->spe['s'] = fpf_string_handler;
	spe->spe['S'] = fpf_string_handler;
	spe->spe['c'] = fpf_character_handler;
	spe->spe['C'] = fpf_character_handler;
	spe->spe['d'] = fpf_signed_handler;
	spe->spe['D'] = fpf_signed_handler;
	spe->spe['i'] = fpf_signed_handler;
	spe->spe['o'] = fpf_unsigned_handler;
	spe->spe['O'] = fpf_unsigned_handler;
	spe->spe['u'] = fpf_unsigned_handler;
	spe->spe['U'] = fpf_unsigned_handler;
	spe->spe['%'] = fpf_prc_handle;
	spe->spe['x'] = fpf_unsigned_handler;
	spe->spe['X'] = fpf_unsigned_handler;
	spe->spe['b'] = fpf_unsigned_handler;
}

void	fpf_init_buff(void)
{
	int n;

	n = 0;
	while (n < BUFF_MAX)
	{
		g_buff[n] = '\0';
		n++;
	}
	g_i = 0;
}

int		fpf_check_spec_bis(PF *argument)
{
	if (argument->format[argument->index] == 'c')
		argument->spec = 'c';
	else if (argument->format[argument->index] == 'C')
		argument->spec = 'C';
	else if (argument->format[argument->index] == 'F')
		argument->spec = 'F';
	else if (argument->format[argument->index] == 'f')
		argument->spec = 'f';
	else
		argument->spec = argument->format[argument->index];
	return (argument->index);
}
