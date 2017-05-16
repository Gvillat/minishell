/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_entries.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:57:42 by aschafer          #+#    #+#             */
/*   Updated: 2016/03/20 19:23:16 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		print_prompt(void)
{
	char			path[255];
	struct passwd	*p;
	char			*lol;

	p = getpwuid(getuid());
	getcwd(path, sizeof(path));
	ft_putstr_color(p->pw_name, 3);
	ft_putstr(" in ");
	ft_putstr_color(path, 2);
	ft_putstr("\n");
	lol = lst_get_value("PROMPT");
	if (lol && lol[0])
		ft_putstr(lst_get_value("PROMPT"));
	else
		ft_putstr("$> ");
}

static int	read_line(char *str)
{
	while (1)
	{
		if (!(g_inf->ret += read(0, str + g_inf->ret, 1024)) ||
		str[g_inf->ret - 1] == '\n')
		{
			if (!g_inf->ret)
				str[0] = '\0';
			else
				str[g_inf->ret - 1] = '\0';
			break ;
		}
	}
	return (g_inf->ret);
}

static int	read_entry(void)
{
	if (g_inf->string)
	{
		ft_memdel((void **)&(g_inf->string));
		g_inf->string = ft_strnew(1024);
	}
	else
		g_inf->string = ft_strnew(1024);
	print_prompt();
	return (read_line(g_inf->string));
}

int			read_entries(void)
{
	char	**cmd;
	int		i;

	i = 0;
	while (!g_inf->exittator && read_entry())
	{
		if (g_inf->string[0])
		{
			cmd = ft_strsplit(g_inf->string, ';');
			while (cmd && cmd[i] && !g_inf->exittator)
				try_entry(cmd[i++]);
			free_tab_ptr(&cmd);
		}
		g_inf->ret = 0;
		i = 0;
	}
	return (0);
}
