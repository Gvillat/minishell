/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:54:35 by gvillat           #+#    #+#             */
/*   Updated: 2017/05/22 15:54:41 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*ft_env(char **args, t_env *lst)
{
	t_env *tmp;

	(void)args;
	if (!lst)
		print_error("env: environnement introuvable", "", "");
	tmp = lst;
	while (tmp)
	{
		fpf_printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
	return (lst);
}

t_env	*ft_setenv(char **args, t_env *lst)
{
	char	*arg[2];
	t_env	*tmp;

	if (!args[1])
		ft_env(args, lst);
	else
	{
		arg[0] = args[1];
		arg[1] = args[2];
		if (!args[2])
			arg[1] = "(null)";
		if ((tmp = lst_search_env(arg[0], lst)))
			tmp->value = arg[1];
		else
			lst_add_env(arg, lst->next);
	}
	return (lst);
}

t_env	*ft_unsetenv(char **args, t_env *lst)
{
	if (!args[1])
		print_error("Usage: unsetenv 'variable'", "", "");
	else
		lst = lst_del_env(args[1], lst);
	return (lst);
}

t_env	*ft_echo(char **args, t_env *lst)
{
	int i;

	i = 1;
	while (args[i])
	{
		fpf_printf("%s ", args[i]);
		i++;
	}
	ft_putchar('\n');
	return (lst);
}
