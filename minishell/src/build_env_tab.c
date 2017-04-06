/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_env_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 15:36:02 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/19 19:36:31 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*build_string(char *key, char *value)
{
	static char buffer[1000];

	ft_memset(buffer, 0, 1000);
	ft_strcat(buffer, key);
	ft_strcat(buffer, "=");
	ft_strcat(buffer, value);
	return (ft_strdup(buffer));
}

static void	add_string(char *key, void *value, size_t size, void *ptr)
{
	int		i;
	char	**tab;

	tab = (char **)ptr;
	i = 0;
	while (tab[i])
		++i;
	tab[i] = build_string(key, (char *)value);
	(void)size;
}

char		**build_env_tab(void)
{
	int		i;
	char	**tab;

	if (!(i = hash_count(g_env)))
		return (NULL);
	++i;
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * i)))
		return (NULL);
	hash_foreach(g_env, add_string, (void *)tab);
	return (tab);
}
