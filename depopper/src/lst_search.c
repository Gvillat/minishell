/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:56:28 by aschafer          #+#    #+#             */
/*   Updated: 2016/03/19 22:56:40 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

LE	*lst_search(char *clef, LE **first)
{
	LE *curr;

	curr = *first;
	while (curr && ft_strcmp(clef, curr->clef))
		curr = curr->next;
	if (!curr)
		return (NULL);
	return (curr);
}
