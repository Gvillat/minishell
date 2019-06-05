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

t_env		*ft_env(char **args, t_env *lst)
{
	t_env *tmp;

	(void)args;
	if (!lst)
		print_error("env: environnement introuvable", "", "");
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

t_env		*ft_setenv(char **args, t_env *lst) 
{
	char	*tmp[2];
	t_env	*tlst;

	if (!args[1] || args[4] || (args[3] && !ft_strfulldigit(args[3]))
		|| ft_strrchr(args[1], '='))
		print_error("usage: setenv key value overwrite", "", "");
	else
	{
		tmp[0] = args[1];
		(!args[2]) ? (tmp[1] =  "(null)") : (tmp[1] = args[2]);
		if ((tlst = lst_search_env(tmp[0], lst)) && args[3] && ft_atoi(args[3]) && args[2])
				tlst->value = tmp[1];
		else if (!lst_search_env(tmp[0], lst))
			lst_add_env(tmp, lst->next);
	}
	return (lst);
}

t_env		*ft_unsetenv(char **args, t_env *lst)
{
	t_env *tmp;

	tmp = lst;
	if (!args[1] || args[2])
		print_error("usage: unsetenv key value overwrite", "", "");
	if ((tmp = lst_search_env(args[1], lst)))
		lst = lst_del_env(args[1], tmp);
	return (lst);
}

t_env		*ft_echo(char **args, t_env *lst)
{
	int i;
	t_env *tmp;

	i = 0;
	if (args[1] && (!ft_strcmp(args[1], "-n")))
		i++;
	while (args[++i])
	{
		if (args[i][0] == '$')
		{
			if ((tmp = lst_search_env(&args[i][1], lst)) && tmp)
				ft_printf("%s ", tmp->value);
			else if (args[i][1] == '?')
				ft_printf("%d ", g_ret);
			else
				ft_printf("%s ", args[i]);
		}
		else
			ft_printf("%s ", args[i]);
	}
	if (args[1] && (ft_strcmp(args[1], "-n")))
		ft_putchar('\n');
	return (lst);
}
