/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:57:17 by aschafer          #+#    #+#             */
/*   Updated: 2016/03/20 19:41:54 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

INF *g_inf;
LE *g_lst;

int	main(int ac, char **av, char **environ)
{
	(void)ac;
	if (!*environ)
		chut(av, environ);
	fill_all(environ);
	signal(SIGINT, signal_handler);
	signal(11, signal_handler);
	read_entries();
	free_all(&g_lst);
	return (0);
}
