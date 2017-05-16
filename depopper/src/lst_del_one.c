/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:52:55 by aschafer          #+#    #+#             */
/*   Updated: 2016/03/19 22:53:28 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		free_lst(LE *curr)
{
	ft_memdel((void **)&curr->string);
	ft_memdel((void **)&curr->clef);
	ft_memdel((void **)&curr->value);
	ft_memdel((void **)&curr);
}

static int		lst_dell(LE **prev, LE *curr)
{
	LE *temp;

	if (!curr->next)
		temp = NULL;
	else
		temp = curr->next;
	(*prev)->next = temp;
	free_lst(curr);
	return (0);
}

int				lst_del_one(LE **first, char *entry)
{
	LE *curr;

	curr = *first;
	while (curr)
	{
		if (curr == *first)
		{
			if (!ft_strncmp(curr->clef, entry, ft_strlen(entry)))
			{
				*first = curr->next;
				free_lst(curr);
				return (0);
			}
		}
		if (!ft_strncmp(curr->next->clef, entry,
		ft_strlen(entry)))
			return (lst_dell(&curr, curr->next));
		curr = curr->next;
	}
	return (-1);
}
