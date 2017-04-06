/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 17:08:28 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/20 14:52:06 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

BOOL	exec_builtin(char **cmd)
{
	static	t_builtins	builtins[] = {
									{"cd", bi_cd},
									{"exit", bi_exit},
									{"env", bi_env},
									{"setenv", bi_setenv},
									{"unsetenv", bi_unsetenv},
									{"setprompt", bi_setprompt}};
	int					i;

	i = 0;
	while (i < NBBUILTINS)
	{
		if (ft_strequ(cmd[0], builtins[i].name))
		{
			builtins[i].func(cmd + 1);
			return (TRUE);
		}
		++i;
	}
	return (FALSE);
}
