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
		cmd = ft_tilted(cmd, lst);
	else if (((tmp = ft_strsplit(cmd, "=")) && tmp[0] && tmp[1] && !tmp[2]))
	{
		g_lst = lst_add_env(tmp, g_lst);
		free(tmp);
	}
	else if (cmd[0] == '$' && &cmd[1] && g_lst && (tlst = lst_search_env(&cmd[1], g_lst)))
		cmd = ft_strdup(tlst->value);
	return (cmd);	
}

int exec_tok(char **cmd, t_env *lst)
{
	int i;

	i = -1;
	while (cmd[++i])
		cmd[i] = cmd_replacer(cmd[i], lst);
	if (!(run_file(cmd, &lst)) && !(run_builtins(cmd, &lst)))
		if (!run_path(cmd, &lst))
			return (print_error("minishell: ", "command not found: ", cmd[0]));
	return (0);
}

int 	parse_tok(char *cmd, t_env *lst)
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
				exec_tok(tmp, lst);
			tab++;
		}
		free(tmp);
	}
	// free(tab);
	return (1);
}
