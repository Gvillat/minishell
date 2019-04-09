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

static t_env	*climb_the_ladder(t_env *lst)
{
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

char			**parse_and_exec(char **cmd, t_env **lst)
{
	char	**tab;
	char	**tmp;
	int		i;

	tab = NULL;
	tmp = NULL;
	i = 0;
	if (!cmd)
		return (NULL);
	if ((tab = ft_strsplit(*cmd, ';')))
	{
		while (*tab && tab[i] && g_running)
		{
			if ((tmp = ft_strsplit(tab[i], ' ')) && *tmp)
			{
				if (!(run_file(tmp, lst)) && !(run_builtins(tmp, lst)))
					run_path(tmp, lst);
				ft_memdel((void**)&tmp);
			}
			i++;
		}
	}
	if ((*lst)->prev)
		*lst = climb_the_ladder(*lst);
	return (tab);
}
