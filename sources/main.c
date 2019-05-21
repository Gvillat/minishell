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

t_env			*ft_exit(char **args, t_env *lst)
{
	if (args[1])
	{
		g_ret = ft_atoi(args[1]);
		exit (g_ret);
		g_running = 0;
	}
	else
		g_running = 0;
	return (lst);
}

t_env			*print_error(char *from, char *str1, char *str2, t_env *lst)
{
	ft_putstr_fd(from, 2);
	if (str1)
		ft_putstr_fd(str1, 2);
	if (str2)
		ft_putendl_fd(str2, 2);
	return (lst);
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
		g_running = 0;
		ft_putchar('\n');
		return ;
	}
}

int				main(int ac, char **av, char **env)
{
	t_env	*lst;
	t_env	*tlst;
	char	*line;
	char	**cmd;
	t_env *tmp;

 	g_lst = NULL;	
	lst = NULL;
	tlst = NULL;
	line = NULL;
	cmd = NULL;	
	(void)ac;
	(void)av;
	if (!(lst = build_lst_env(env, lst)))
		lst = build_no_env();
	else
		lst_add_lvl(lst);
	while (g_running)
	{
		tmp = lst;
		print_prompt(tmp);
		if (!get_next_line(0, &line))
			g_running = 0;
		else
		{
			cmd = parse_tok(line, lst);
			free(line);
		}
	}
	signal(SIGINT, sig_handler);
	return (g_ret);
}

// 
		
// 		parse_and_exec(&cmd, &lst);
// 		// ft_memdel((void **)&cmd);
// 	}
// 	(void)argc;
// 	(void)argv;
