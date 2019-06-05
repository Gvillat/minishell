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

char			*ft_tilted(char *args, t_env *lst)
{
	t_env		*tmp;

	tmp = lst;
	if (ft_strchr(args, '-') && (tmp = lst_search_env("OLDPWD", lst)))
		args = ft_strjoin(tmp->value, ft_strrchr(args, '~') + 2);
	else if (ft_strchr(args, '+') && (tmp = lst_search_env("PWD", lst)))
		args = ft_strjoin(tmp->value, ft_strrchr(args, '~')+ 2);
	else if (ft_strchr(args, '~') && (tmp = lst_search_env("HOME", lst)))
		args = ft_strjoin(tmp->value, ft_strrchr(args, '~') + 1);
	return (args);
}


char *cmd_replacer(char *cmd, t_env *lst)
{
	char **tmp;
	t_env *tlst;

 	tmp = NULL;
	tlst = NULL;
	if (ft_strchr(cmd, '~') && (lst_search_env("HOME", lst)))
		return (cmd = ft_tilted(cmd, lst));
	if (((tmp = ft_strsplit(cmd, "=")) && tmp[0] && tmp[1] && !tmp[2]))
	{
		g_lst = lst_add_env(tmp, g_lst);
		free(tmp);
		free(cmd);
		return ("test");
	}
	if (cmd[0] == '$' && &cmd[1] && g_lst && (tlst = lst_search_env(&cmd[1], g_lst)))
	{
		free(cmd);
		return (cmd = ft_strdup(tlst->value));
	}
	return (cmd);	
}

t_env *exec_tok(char **cmd, t_env *lst)
{
	int i;

	i = -1;
	while (cmd[++i])
		cmd[i] = cmd_replacer(cmd[i], lst);
	if (!(run_file(cmd, &lst)) && !(run_builtins(cmd, &lst)))
		if (!run_path(cmd, &lst))
			print_error("minishell: ", "command not found: ", cmd[0]);
	return (lst);
}

t_env 	*parse_tok(char *cmd, t_env *lst)
{
	char	**tab;
	char	**tmp;

	tab = NULL;
	tmp = NULL;
	if ((tab = ft_strsplit(cmd, ";")) && *tab)
	{
		while (*tab)
		{
			if ((tmp = ft_strsplit(*tab, " \t")) && *tmp && lst)
				lst = exec_tok(tmp, lst);
			tab++;
		}
		free(tmp);
	}
	// if (tab)
		// free(tab);
	return (lst);
}
