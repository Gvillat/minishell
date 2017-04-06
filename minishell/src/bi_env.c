/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 15:09:55 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/19 15:26:15 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		print_var(char *key, void *value, size_t size, void *ptr)
{
	ft_putstr(key);
	ft_putchar('=');
	ft_putstr(value);
	ft_putchar('\n');
	(void)size;
	(void)ptr;
}

void			bi_env(char **args)
{
	hash_foreach(g_env, print_var, NULL);
	(void)args;
}
