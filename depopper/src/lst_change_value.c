/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_change_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:52:42 by aschafer          #+#    #+#             */
/*   Updated: 2016/03/19 22:53:58 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lst_change_value(char *clef, char *new_val)
{
	LE		*curr;
	char	*tmp;
	char	*tmp2;

	curr = lst_search(clef, &g_lst);
	if (curr)
	{
		free(curr->string);
		if (curr->value)
			free(curr->value);
		tmp = ft_strjoin(curr->clef, "=");
		tmp2 = ft_strjoin(tmp, new_val);
		curr->string = tmp2;
		free(tmp);
		curr->value = new_val;
	}
}
