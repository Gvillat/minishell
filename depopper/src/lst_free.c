/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:54:38 by aschafer          #+#    #+#             */
/*   Updated: 2016/03/19 22:55:03 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
}

void		free_tab_ptr(char ***tb)
{
	free_tab(*tb);
	ft_memdel((void **)tb);
}

void		lst_free(LE *curr)
{
	if (curr)
	{
		if (curr->next)
			lst_free(curr->next);
		if (curr->string)
			free(curr->string);
		free(curr->clef);
		if (curr->value)
			free(curr->value);
		if (curr->next)
			free(curr->next);
	}
}
