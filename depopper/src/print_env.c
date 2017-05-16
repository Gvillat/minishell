/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:57:29 by aschafer          #+#    #+#             */
/*   Updated: 2016/03/20 19:42:31 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(char **ffff)
{
	LE *entry;

	(void)ffff;
	entry = g_lst;
	while (entry)
	{
		ft_putstr(entry->clef);
		ft_putstr("=");
		ft_putendl(entry->value);
		entry = entry->next;
	}
}
