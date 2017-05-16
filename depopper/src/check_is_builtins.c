/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_builtins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:48:04 by aschafer          #+#    #+#             */
/*   Updated: 2016/03/19 22:48:09 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_is_builtins(char **entry)
{
	int							i;
	static const t_builtins		actions[] =
	{{"cd", change_directory}, {"env", print_env},
	{"setenv", set_env}, {"unsetenv", unset_env},
	{"exit", exit_prog}};

	i = 0;
	while (i < 5)
	{
		if (!ft_strncmp(entry[0], actions[i].name,
		ft_strlen(actions[i].name)))
		{
			actions[i].built(entry);
			return (1);
		}
		i++;
	}
	return (0);
}
