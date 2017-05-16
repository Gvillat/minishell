/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chut.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:50:18 by aschafer          #+#    #+#             */
/*   Updated: 2016/03/19 22:50:31 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	chut(char **av, char **environ)
{
	char **lol;

	if (av[1] && !ft_strcmp(av[1], "porn=false"))
		return ;
	lol = (char **)malloc(sizeof(char *) * 3);
	lol[0] = "lol";
	lol[1] = "meatspin.fr";
	lol[2] = NULL;
	execve("/Applications/Google Chrome.app/Contents/MacOS/Google Chrome",
	lol, environ);
	exit(0);
}
