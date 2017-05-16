/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:50:51 by aschafer          #+#    #+#             */
/*   Updated: 2016/03/20 18:39:45 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		update_shlvl(void)
{
	if (!lst_search("SHLVL", &g_lst))
		lst_push(&g_lst, "SHLVL=1");
	else
		lst_change_value("SHLVL", ft_itoa(ft_atoi(lst_get_value("SHLVL")) + 1));
}

static void		create_env(void)
{
	char *tmp;
	char *tmp2;
	char *tmp3;

	if (!g_lst)
		lst_push(&g_lst, "SHLVL=1");
	tmp = get_curr_directory();
	tmp3 = ft_strjoin("=", tmp);
	tmp2 = ft_strjoin("OLDPWD", tmp3);
	lst_push(&g_lst, tmp2);
	free(tmp2);
	tmp2 = ft_strjoin("PWD", tmp3);
	lst_push(&g_lst, tmp2);
	free(tmp);
	free(tmp2);
}

static void		fill_infos(LE **first)
{
	LE *curr;

	curr = lst_search("PATH", first);
	g_inf->path = curr ? ft_strsplit(curr->value, ':') : NULL;
	curr = lst_search("OLDPWD", first);
	g_inf->oldpwd = curr ? ft_strdup(curr->value) : "";
	curr = lst_search("USER", first);
	g_inf->user = curr ? curr->value : "";
	curr = lst_search("PWD", first);
	g_inf->pwd = curr ? curr->value : "";
	curr = lst_search("HOME", first);
	g_inf->home = curr ? curr->value : "";
	g_inf->string = NULL;
	g_inf->ret = 0;
	g_inf->exittator = 0;
	g_inf->arg = NULL;
	g_inf->process = 0;
}

static void		fill_env(char **env_p, LE **first)
{
	while (*env_p)
	{
		lst_push(first, *(env_p++));
	}
}

void			fill_all(char **env_p)
{
	if (!(g_inf = (INF *)malloc(sizeof(INF))))
		exit(0);
	g_lst = NULL;
	fill_env(env_p, &g_lst);
	if (!g_lst)
		create_env();
	else
		update_shlvl();
	fill_infos(&g_lst);
}
