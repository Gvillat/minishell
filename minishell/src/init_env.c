/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 14:30:07 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/20 14:24:03 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "minishell.h"

void		init_env(char **envp)
{
	int		i;
	char	**tab;

	i = 0;
	while (envp[i])
	{
		if (!(tab = ft_strsplit(envp[i], '=')))
			ft_errexit("malloc failed");
		hash_set(&g_env, tab[0], tab[1], ft_strlen(tab[1]) + 1);
		ft_freetab((void **)tab);
		++i;
	}
}
