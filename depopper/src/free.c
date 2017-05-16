/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:52:32 by aschafer          #+#    #+#             */
/*   Updated: 2016/03/19 22:52:39 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_all(LE **first)
{
	if (g_inf->string)
		ft_memdel((void **)&(g_inf->string));
	if (g_inf->path)
		free_tab_ptr(&(g_inf->path));
	if (g_inf->arg)
		free(g_inf->arg);
	if (g_inf->oldpwd)
		free(g_inf->oldpwd);
	free(g_inf);
	lst_free(*first);
	if (*first)
		free(*first);
}
