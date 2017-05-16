/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_get_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:55:13 by aschafer          #+#    #+#             */
/*   Updated: 2016/03/19 22:55:24 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*lst_get_value(char *clef)
{
	LE *curr;

	curr = lst_search(clef, &g_lst);
	if (curr && curr->value)
		return (curr->value);
	return (NULL);
}
