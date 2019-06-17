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
	char		*str;

	str = NULL;
	if (ft_strchr(args, '-') && (tmp = lst_search_env("OLDPWD", lst)))
	{
		str = ft_strjoin(tmp->value, ft_strrchr(args, '~') + 2);
		free(args);
		args = str;
	}
	else if (ft_strchr(args, '+') && (tmp = lst_search_env("PWD", lst)))
	{
		str = ft_strjoin(tmp->value, ft_strrchr(args, '~')+ 2);
		free(args);
		args = str;
	}
	else if (ft_strchr(args, '~') && (tmp = lst_search_env("HOME", lst)))
	{
		str = ft_strjoin(tmp->value, ft_strrchr(args, '~') + 1);
		free(args);
		args = str;
	}
	return (args);
}


int total_exp(char *cmd)
{
	char **tmp;

	tmp = NULL;
	if (!cmd)
		return (0);
	tmp = ft_strsplit(cmd, "=");
	if (tmp[0] && tmp[1] && !tmp[2])
	{
		if (!(lst_search_env(tmp[0], g_lst)))
			g_lst = lst_add_env(tmp, g_lst);
		else
		{
			g_lst = lst_del_env(tmp[0], g_lst);
			g_lst = lst_add_env(tmp, g_lst);
		}
	}
	else
	{	
		ft_free_tab(tmp);
		return (0);
	}
	ft_free_tab(tmp);
	return (1);
}

char *cmd_replacer(char *cmd, t_env *lst)
{
	t_env *tlst;

	tlst = NULL;
	if (ft_strchr(cmd, '~') && (lst_search_env("HOME", lst)))
		return (ft_tilted(cmd, lst));
	else if (ft_strchr(cmd, '='))
	{
		if (total_exp(cmd))
		{
			free(cmd);
			return (ft_strdup("test"));
		}
	}
	else if (cmd[0] == '$' && &cmd[1] && g_lst
		&& (tlst = lst_search_env(&cmd[1], g_lst)))
	{
		free(cmd);
		return ((cmd = ft_strdup(tlst->value)));
	}
	return (cmd);	
}

t_env *exec_tok(char *cmd, t_env *lst)
{
	int i;
	char **tmp;

	i = -1;
	if (!*cmd)
		return (lst);
	if ((tmp = ft_strsplit(cmd, " \t")) && *tmp)
	{
		while (tmp[++i])
			tmp[i] = cmd_replacer(tmp[i], lst);
		if (!(run_file(tmp, &lst)) && !(run_builtins(tmp, &lst)))
		{
			if (!run_path(tmp, &lst))
				print_error("minishell: ", "command not found: ", tmp[0]);
		}
	}
	ft_free_tab(tmp);
	return (lst);
}

t_env 	*parse_tok(char *line, t_env *lst)
{
	char	**tmp;
	char	**tab;
	int 	i;

	i = 0;
	tmp = NULL;
	tab = NULL;
	tab = ft_strsplit(line, ";");
	while (tab[i] && tab)
	{
		lst = exec_tok(tab[i], lst);
		free(tab[i]);
		i++;
	}
	// ft_free_tab(tab);
	free(tab);
	ft_strdel(&line);
	return (lst);
}
