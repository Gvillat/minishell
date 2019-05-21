/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_build_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:06:58 by guvillat          #+#    #+#             */
/*   Updated: 2019/04/01 13:07:00 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static t_env	*go_to(char *path, t_env *lst)
{
	static struct stat	st;
	char				*str;

	if (access(path, F_OK) == -1)
		return (print_error("cd: ", "no such file or directory: ", path, lst));
	if (stat(path, &st) == -1)
		return (print_error("cd: ", "stat error: ", path, lst));
	if (!(S_ISDIR(st.st_mode)))
		return (print_error("cd: ", "not a directory: ", path, lst));
	if (access(path, R_OK) == -1)
		return (print_error("cd: ", "permission denied: ", path, lst));
	if ((lst = lst_search_env("PWD", lst)))
	{
		str = lst->value;
		if (!chdir(path))
		{
			path = getcwd(NULL, 0);
			lst->value = path;
		}
	}
	if ((lst = lst_search_env("OLDPWD", lst)))
		lst->value = str;
	return (lst);
}

t_env			*ft_cd(char **args, t_env *lst)
{
	int		i;

	if (!lst_search_env("HOME", lst))
	{
		ft_printf("minishell: cd: HOME not set\n");
		return (lst);
	}
	if (ft_strequ(args[0], "cd") && !args[1] && lst_search_env("HOME", lst))
		go_to(lst_search_env("HOME", lst)->value, lst);
	i = 0;
	while (args[++i])
	{
		if (ft_strequ(args[i], "-") && lst_search_env("OLDPWD", lst))
			go_to(lst_search_env("OLDPWD", lst)->value, lst);
		// else if (args[i][0] == '~')
		// 	ft_tilted(args[i], lst);
		else
			go_to(args[i], lst);
	}
	return (lst);
}

t_env *build_no_env(void)
{
	char *tmp[4];
	char **str;
	char pwd[4096];
	int i;
	t_env *tlst;

	i = 0;
	tlst = NULL;
	*tmp = NULL;
	tmp[0] = "PWD=";
	if (getcwd(pwd, sizeof(pwd)) != NULL)
		tmp[0] = ft_strjoin(tmp[0], pwd);
	tmp[1] = "SHLVL=1";
	tmp[2] = "_=/usr/bin/env";
	tmp[3] = NULL;
	while (tmp[i])
	{
		str = ft_strsplit(tmp[i], "=");
		tlst = lst_add_env(str, tlst);
		i++;
	}
	return (tlst);
}

t_env			*build_lst_env(char **env, t_env *lst)
{
	char	**tmp;
	int		i;
	char	*prpt[2];
	t_env 	*tlst;

	prpt[0] = "PROMPT";
	prpt[1] = "$>";
	i = 0;
	lst = NULL;
	while (env[i])
	{
		tmp = ft_strsplit(env[i], "=");
		lst = lst_add_env(tmp, lst);
		i++;
		free(tmp);
	}
	if (!(tlst = lst_search_env("PROMPT", lst)) && lst)
		lst_add_env(prpt, lst);
	return (lst);
}

char			**build_env_tab(t_env *lst)
{
	int		i;
	int		j;
	char	**tab;
	char	*tmp;
	t_env	*tlst;

	i = 0;
	j = -1;
	tlst = lst;
	while (tlst)
	{
		i++;
		tlst = tlst->next;
	}
	if (!(tab = (char**)ft_memalloc(sizeof(char *) * i)))
		return (NULL);
	tab[i] = NULL;
	while (lst && j++ < i)
	{
		tmp = ft_strjoin(ft_strjoin(lst->key, "="), lst->value);
		tab[j] = ft_strdup(tmp);
		lst = lst->next;
		free(tmp);
	}
	return (tab);
}

void			free_lst(t_env *lst)
{
	t_env *curr;

	while (lst)
	{
		curr = lst;
		free(curr);
		lst = lst->next;
	}
}
