/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 23:00:26 by aschafer          #+#    #+#             */
/*   Updated: 2016/03/20 19:43:38 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		update_lst(LE *curr, char **av)
{
	char *str;
	char *tmp;

	free(curr->value);
	free(curr->string);
	if (av[2])
		curr->value = ft_strdup(av[2]);
	else
		curr->value = ft_strdup("\0");
	tmp = ft_strjoin(av[1], "=");
	if (!av[2])
		str = ft_strjoin(tmp, "");
	else
		str = ft_strjoin(tmp, av[2]);
	free(tmp);
	curr->string = str;
}

static void	add_lst(char **entry)
{
	char *tmp;
	char *tmp2;

	tmp = ft_strjoin(entry[1], "=");
	if (entry[2])
	{
		tmp2 = ft_strjoin(tmp, entry[2]);
		lst_push(&g_lst, tmp2);
		free(tmp2);
	}
	else
	{
		tmp2 = tmp;
		lst_push(&g_lst, tmp2);
	}
	free(tmp);
}

void		set_env(char **entry)
{
	LE		*curr;
	int		i;

	i = 0;
	while (entry[i])
		i++;
	if (i == 1)
		print_env(entry);
	else if (i > 3)
		return (error("setenv: ", "Too many arguments"));
	else if ((curr = lst_search(entry[1], &g_lst)))
		update_lst(curr, entry);
	else
		add_lst(entry);
}
