/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:55:34 by aschafer          #+#    #+#             */
/*   Updated: 2016/03/19 22:55:55 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>

LE	*lst_new(char *string)
{
	LE		*new;
	char	**cv;
	char	*up;

	if (!(new = (LE *)malloc(sizeof(LE))))
		exit(1);
	cv = ft_strsplit(string, '=');
	new->string = ft_strdup(string);
	new->clef = cv[0];
	if (ft_countwords(string, '=') > 2)
	{
		up = ft_strjoin(cv[1], cv[2]);
		free(cv[1]);
		free(cv[2]);
		new->value = up;
	}
	else
		new->value = cv[1];
	if (!new->value)
		new->value = ft_strdup("");
	new->next = NULL;
	free(cv);
	return (new);
}
