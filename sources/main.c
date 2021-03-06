/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:55:13 by gvillat           #+#    #+#             */
/*   Updated: 2017/05/22 15:55:15 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int g_running = 1;

t_env			*ft_exit(char **args, t_env *lst)
{
	g_running = 0;
	(void)args;
	return (lst);
}

void			print_error(char *from, char *str1, char *str2)
{
	ft_putstr_fd(from, 2);
	if (str1)
		ft_putstr_fd(str1, 2);
	if (str2)
		ft_putendl_fd(str2, 2);
}

void			print_prompt(t_env *lst)
{
	t_env *tmp;

	if (!lst)
		g_running = 0;
	if ((tmp = lst_search_env("PROMPT", lst)))
		ft_putstr(tmp->value);
	else
		ft_putstr("<3");
}

static void		sig_handler(int id)
{
	if (id == SIGINT)
	{
		ft_putchar('\n');
		return ;
	}
}

int				main(int argc, char *argv[], char *env[])
{
	t_env	*lst;
	char	*cmd;

	lst = NULL;
	cmd = NULL;
	lst = build_lst_env(env, lst);
	signal(SIGINT, sig_handler);
	while (g_running)
	{
		print_prompt(lst);
		get_next_line(0, &cmd);
		parse_and_exec(&cmd, &lst);
		ft_memdel((void **)&cmd);
	}
	free(cmd);
	free_lst(lst);
	(void)argc;
	(void)argv;
	return (0);
}
