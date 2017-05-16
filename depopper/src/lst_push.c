/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:56:22 by aschafer          #+#    #+#             */
/*   Updated: 2016/03/19 22:56:23 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lst_push(LE **first, char *string)
{
	LE *curr;

	if (!(curr = *first))
	{
		*first = lst_new(string);
		return ;
	}
	while (curr->next)
		curr = curr->next;
	curr->next = lst_new(string);
}
