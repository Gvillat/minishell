/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 23:01:53 by aschafer          #+#    #+#             */
/*   Updated: 2016/03/19 23:01:57 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_env(char **entry)
{
	int i;

	i = 1;
	if (!entry[1])
		return (error("Usage: unsetenv 'variable'", ""));
	while (entry[i])
	{
		if (lst_del_one(&g_lst, entry[i]) == -1)
			error("unsetenv: variable introuvable", "");
		i++;
	}
}
