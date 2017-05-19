#include "../includes/minishell.h"
#include <stdio.h>

int g_running = 1;

void	print_error(char *from, char *str1, char *str2)
{
	ft_putstr_fd(from, 2);
	if (str1)
		ft_putstr_fd(str1, 2);
	if (str2)
		ft_putendl_fd(str2, 2);
}

static void print_prompt(t_env *lst)
{
	t_env *tmp;

	if (!lst)
		g_running = 0;
	if ((tmp = lst_search_env("PROMPT", lst)))
		ft_putstr(tmp->value);
	else
		ft_putstr("<3");
}

static void	sig_handler(int id)
{
	if (id == SIGINT)
	{
		ft_putchar('\n');
		return ;
	}
}

int main(int argc, char *argv[], char *env[])
{
	t_env *lst;
	char *cmd;
	char **tab;

	lst = build_lst_env(env, lst);
	while (g_running)
	{	
		print_prompt(lst);
		get_next_line(0, &cmd);
		parse_and_exec(&cmd, &lst);
		ft_memdel((void **)&cmd);
	}
	(void)argc;
	(void)argv;
	free_lst(&lst);
	return(0);
}