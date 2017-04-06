/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 18:15:36 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/19 18:46:52 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bi_unsetenv(char **args)
{
	int i;

	i = 0;
	if (!args[0])
		return (print_error("unsetenv: ", "you given no key\n", NULL));
	while (args[i])
		hash_unset(&g_env, args[i++], del_hash);
}
