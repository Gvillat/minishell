/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:07:30 by guvillat          #+#    #+#             */
/*   Updated: 2019/04/01 13:07:43 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// static t_env	*climb_the_ladder(t_env *lst)
// {
// 	while (lst->prev)
// 		lst = lst->prev;
// 	return (lst);
// }

t_env			*ft_tilted(char *args, t_env *lst)
{
	t_env		*tmp;
	char	buf[4096];

	ft_memset(buf, 0, 4096);
	tmp = lst;
	if (args[0] == '~' && args[1] == '+')
	{	
		// go_to(lst_search_env("PWD", lst)->value, lst);
		ft_strcat(buf, ft_strchr(args, '~'));
		ft_strcat(buf, args);
		args = ft_strdup(buf);
		ft_printf("%s\n", args);
		// go_to(args, tmp);
		// free(buf);
	}
	else if (args[0] == '~' && args[1] == '-')
	{
		// go_to(lst_search_env("OLDPWD", lst)->value, lst);
		ft_strcat(buf, lst_search_env("OLDPWD", tmp)->value);
		ft_strcat(buf, args);
		args = ft_strdup(buf);
		ft_printf("%s\n", args);
		// go_to(args, tmp);
		// free(buf);
	}
	else
	{
		// go_to(lst_search_env("HOME", lst)->value, lst);
		ft_strcat(buf, lst_search_env("HOME", tmp)->value);
		ft_strcat(buf, args);
		args = ft_strdup(buf);
		ft_printf("%s\n", args);
		// go_to(args, tmp);
		// free(buf);
	}
	return (lst);
}


char *cmd_replacer(char *cmd, t_env *lst)
{
	char **tmp;
	t_env *tlst;

 	tmp = NULL;
	tlst = NULL;
	if ((ft_strequ(cmd, "~")) && (tlst = lst_search_env("HOME", lst)))
	{
		printf("toto\n");
		ft_tilted(cmd, tlst);
	}
	else if (((tmp = ft_strsplit(cmd, "=")) && tmp[0] && tmp[1] && !tmp[2]))
	{
		g_lst = lst_add_env(tmp, g_lst);
		free(tmp);
	}
	else if (cmd[0] == '$' && &cmd[1] && g_lst && (tlst = lst_search_env(&cmd[1], g_lst)))
		cmd = ft_strdup(tlst->value);
	return (cmd);	
}

char			**parse_tok(char *cmd, t_env *lst)
{
	char	**tab;
	char	**tmp;

	tab = NULL;
	tmp = NULL;
	if ((tab = ft_strsplit(cmd, ";")) && *tab)
	{
		while (*tab)
		{
			tmp = ft_strsplit(*tab, " \t");
			while (*tmp)
			{
				*tmp = cmd_replacer(*tmp, lst);
				tmp++;
			}
			if (!(run_file(tab, &lst)) && !(run_builtins(tab, &lst)))
				run_path(tab, &lst);
			tab++;
		}
	}
	return (tab);
}
