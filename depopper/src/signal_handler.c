/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 23:00:31 by aschafer          #+#    #+#             */
/*   Updated: 2016/03/20 18:42:26 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_handler(int no)
{
	if (no == SIGINT)
	{
		if (g_inf->process)
			g_inf->process = 0;
		else
		{
			ft_putendl("");
			print_prompt();
		}
	}
	if (no == 11)
	{
		ft_putendl("Fils de pute !!!!!");
		exit(0);
	}
}
