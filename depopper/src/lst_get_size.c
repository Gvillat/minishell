/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_get_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:55:06 by aschafer          #+#    #+#             */
/*   Updated: 2016/03/19 22:56:18 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lst_get_size(LE **first)
{
	int	i;
	LE	*curr;

	i = 0;
	if (!*first)
		return (0);
	curr = *first;
	while (curr)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}
