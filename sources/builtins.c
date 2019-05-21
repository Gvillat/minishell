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

t_env	*ft_env(char **args, t_env *lst)
{
	t_env *tmp;

	(void)args;
	if (!lst)
		return (print_error("env: environnement introuvable", "", "", lst));
	else
	{
		tmp = lst;
		while (tmp)
		{
			ft_printf("%s=%s\n", tmp->key, tmp->value);
			tmp = tmp->next;
		}
	}
	return (lst);
}


//overwrite !!!!!!
t_env	*ft_setenv(char **args, t_env *lst) 
{
	char	*arg[2];
	t_env	*tmp;

	if (!args[1])
		return (print_error("setenv: pas d'argument", "", "", lst));
	else
	{
		if (ft_strrchr(args[1], '='))
			return (print_error("usage: setenv key value", "", "", lst));
		arg[0] = args[1];
		(!args[2]) ? (arg[1] =  "(null)") : (arg[1] = args[2]);
		if ((tmp = lst_search_env(arg[0], lst)))
		{
			if (args[2])
				tmp->value = arg[1];
		}
		else
			lst_add_env(arg, lst->next);
	}
	return (lst);
}

t_env	*ft_unsetenv(char **args, t_env *lst)
{
	t_env	*tmp;
	int		i;

	i = 1;
	if (!args[1])
		return (print_error("Usage: unsetenv 'variable'", "", "", lst));
	else
	{
		while (args[i])
		{
			if ((tmp = lst_search_env(args[i], lst)))
				lst_del_env(args[i], tmp);
			else
				return (print_error("env: variable ", args[i], " introuvable", lst));
			i++;
		}
	}
	return (lst);
}

t_env	*ft_echo(char **args, t_env *lst)
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
	return (lst);
}
