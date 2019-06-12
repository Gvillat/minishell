/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:07:56 by guvillat          #+#    #+#             */
/*   Updated: 2019/04/01 13:07:58 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int g_running = 1;
int g_ret = 0;

void ft_free_lst(t_env *lst)
{
	t_env *tmp;

	tmp = lst;
	while (tmp)
	{
		tmp = lst->next;
		free(lst->value);
		free(lst->key);
		free(lst);
		lst = tmp;
	}
}


t_env		*ft_exit(char **args, t_env *lst)
{
	if (!args[1])
	{
		ft_free_lst(lst);
		if (g_lst)
			ft_free_lst(g_lst);
		exit (0);

	}	// free_lst(lst);
	else if (args[1] && !args[2])
	{
		g_ret = ft_atoi(args[1]);
		ft_free_lst(lst);
		exit (g_ret);
		g_running = 0;
	}
	else
		print_error("exit: ", "too many arguments", "");
	return (lst);
}

int 		print_error(char *from, char *str1, char *str2)
{
	ft_putstr_fd(from, 2);
	if (str1)
		ft_putstr_fd(str1, 2);
	if (str2)
		ft_putendl_fd(str2, 2);
	return (-1);
}

void			print_prompt(t_env *lst)
{
	t_env *tmp;

	if (!lst)
		g_running = 0;
	else if ((tmp = lst_search_env("PROMPT", lst)))
		ft_putstr(tmp->value);
	else
		ft_putstr("<3");
}

static void		sig_handler(int id)
{
	if (id == SIGINT)
	{
		ft_printf("$>");
	}
}

int				main(void)
{
	t_env	*lst;
	char	*line;
	extern char **environ;

 	g_lst = NULL;	
	lst = NULL;
	line = NULL;
	signal(SIGINT, sig_handler);
	if (!(lst = build_lst_env(environ, lst)))
		lst = build_no_env();
	else
		lst_add_lvl(lst);
	while (g_running)
	{
		print_prompt(lst);
		if (!(g_running = get_next_line(0, &line)))
		{
			free(line);
			break ;
		}
		else
		{
			lst = parse_tok(line, lst);
			free(line);
		}
	}
	ft_printf("toto\n");
	ft_free_lst(lst);
	if (g_lst)
		ft_free_lst(g_lst);
	// while (1);
	return (g_ret);
}