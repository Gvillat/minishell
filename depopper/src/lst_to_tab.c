/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:56:43 by aschafer          #+#    #+#             */
/*   Updated: 2016/03/19 22:57:13 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**lst_to_tab(LE **lst)
{
	int		i;
	LE		*curr;

	if (!(i = lst_get_size(&g_lst)))
		return (NULL);
	curr = *lst;
	if (g_inf->arg)
		free(g_inf->arg);
	if (!(g_inf->arg = (char **)malloc((sizeof(char *) * (i + 1)))))
		return (NULL);
	i = 0;
	while (curr)
	{
		g_inf->arg[i++] = curr->string;
		curr = curr->next;
	}
	g_inf->arg[i] = NULL;
	return (g_inf->arg);
}
