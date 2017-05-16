/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_variable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:50:00 by aschafer          #+#    #+#             */
/*   Updated: 2016/03/19 22:50:13 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_is_variable(char *path, char *var, char **new)
{
	int	i;
	LE	*curr;

	i = 0;
	if (path[0] == '$' && ft_isalpha(path[1]))
	{
		path++;
		while (*path && ft_isalpha(*path))
			var[i++] = *(path++);
		if ((curr = lst_search(var, &g_lst)) && curr->value)
		{
			*new = ft_strjoin(curr->value, path);
			return (0);
		}
		return (-1);
	}
	return (1);
}
