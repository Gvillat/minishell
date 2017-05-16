/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_entry.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 23:00:36 by aschafer          #+#    #+#             */
/*   Updated: 2016/03/20 19:42:53 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		is_escaped_arg(char c)
{
	return (ft_isescaped(c) || c == ' ');
}

void			try_entry(char *entry)
{
	char	**av;
	char	*exec;
	pid_t	father;

	av = ft_strsplitif(entry, &is_escaped_arg);
	if (av[0])
	{
		if (!check_is_builtins(av))
		{
			lst_to_tab(&g_lst);
			if ((exec = check_is_exec(av)))
			{
				father = fork();
				g_inf->process = 1;
				if (!father)
					execve(exec, av, lst_to_tab(&g_lst));
				else
					wait(NULL);
				free(exec);
			}
		}
	}
	free_tab_ptr(&av);
}
