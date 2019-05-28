/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:06:41 by guvillat          #+#    #+#             */
/*   Updated: 2019/04/01 13:06:49 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_env(char **args, t_env *lst)
{
	t_env *tmp;

	(void)args;
	if (!lst)
		return (print_error("env: environnement introuvable", "", ""));
	else
	{
		tmp = lst;
		while (tmp)
		{
			ft_printf("%s=%s\n", tmp->key, tmp->value);
			tmp = tmp->next;
		}
	}
	return (1);
}

int		ft_setenv(char **args, t_env *lst) 
{
	char	*tmp[2];
	t_env	*tlst;

	if (!args[1])
		return (print_error("setenv: pas d'argument", "", ""));
	else if (args [4])
		return (print_error("setenv: trop d'argument", "", ""));
	else
	{
		if (ft_strrchr(args[1], '='))
			return (print_error("usage: setenv key value overwrite", "", ""));
		tmp[0] = args[1];
		(!args[2]) ? (tmp[1] =  "(null)") : (tmp[1] = args[2]);
		if ((tlst = lst_search_env(tmp[0], lst)) && args[3] && ft_atoi(args[3]) && args[2])
				tlst->value = tmp[1];
		else if (!lst_search_env(tmp[0], lst))
			lst_add_env(tmp, lst->next);
	}
	return (1);
}

int		ft_unsetenv(char **args, t_env *lst)
{
	t_env	*tmp;
	int		i;

	i = 1;
	if (!args[1])
		return (print_error("Usage: unsetenv 'variable'", "", ""));
	else
	{
		while (args[i])
		{
			if ((tmp = lst_search_env(args[i], lst)))
				lst_del_env(args[i], tmp);
			else
				return (print_error("env: variable ", args[i], " introuvable"));
			i++;
		}
	}
	return (1);
}

int		ft_echo(char **args, t_env *lst)
{
	int i;
	int n;
	t_env *tmp;

	i = 1;
	n = 0;
	if (args[1] && (!ft_strcmp(args[1], "-n")))
	{
		n = 1;
		i++;
	}
	while (args[i])
	{
		if (args[i][0] == '$')
		{
			if ((tmp = lst_search_env(&args[i][1], lst)))
				ft_printf("%s", tmp->value);
			if (args[1][1] == '?')
				ft_printf("%d", g_ret);
		}
		else
			ft_printf("%s ", args[i]);
		i++;
	}
	if (!n)
		ft_putchar('\n');
	return (1);
}
