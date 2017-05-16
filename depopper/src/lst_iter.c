/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:55:27 by aschafer          #+#    #+#             */
/*   Updated: 2016/03/19 22:55:31 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lst_iter(LE **first, void (*f)(LE *entry))
{
	LE *curr;

	if (!(curr = *first))
		return ;
	while (curr)
	{
		f(curr);
		curr = curr->next;
	}
}
