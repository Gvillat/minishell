/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 16:48:33 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/20 21:10:02 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		bi_setenv(char **args)
{
	if (!args[0])
		return (bi_env(args));
	hash_set(&g_env, args[0], args[1] ? args[1] : "",
	args[1] ? ft_strlen(args[1]) + 1 : 0);
}
