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


t_env *lst_new_env(char **name, t_env *lst)
{
	t_env *new;
	size_t size;

	if (!(new = (t_env*)malloc(sizeof(t_env))))
		return(NULL);
	if (!lst)
		size = -1;
	else
	{
		size = lst->size;
	}
	new->key = name[0];
	new->value = name[1];
	new->size = size + 1;
	new->next = NULL;
	new->prev = lst;
	return (new);
}

t_env *lst_add_env(char **tmp, t_env *lst)
{
	t_env *tt;

	if(!lst)
		return (lst = lst_new_env(tmp, NULL));
	tt = lst;
	while (tt->next)
		tt = tt->next;
	tt->next = lst_new_env(tmp, tt);
	return (lst);
}

t_env *lst_search_env(char *name, t_env *lst)
{
	t_env *tmp;

	if (!name || !lst)
		return (NULL);
	tmp = lst;
	while (tmp)
	{
		if (ft_strequ(name, tmp->key))
		{
			return(tmp);
		}
		tmp = tmp->next;
	}
	return (tmp);
}

t_env *lst_add_lvl(t_env *lst)
{
	t_env *tmp;
	int		i;

	tmp = lst;
	tmp = lst_search_env("SHLVL", tmp);
	i = ft_atoi(tmp->value);
	++i;
	tmp->value = ft_itoa(i);
	return (lst);
}

t_env *do_the_dope_walk(char **env, t_env *lst)
{
	char **tmp;
	int i;
	char *prpt[2];
	
	prpt[0] = "PROMPT";
	prpt[1] = "$>";
	i = 0;
	lst = NULL;
	while (env[i])
	{
		tmp = ft_strsplit(env[i], '=');
		lst = lst_add_env(tmp, lst);
		i++;
		free(tmp);
	}
	lst_add_env(prpt, lst);
	return (lst_add_lvl(lst));
}

static void	sig_handler(int id)
{
	if (id == SIGINT)
	{
		ft_putchar('\n');
		return ;
	}
}

char **build_env_tab(t_env *lst)
{
	int i;
	int j;
	char **tab;
	char *tmp;

	i = lst->size + 1;
	// while (lst && lst->prev)
		// lst = lst->prev;
	j = 0;
	if (!(tab = (char**)ft_memalloc(sizeof(char *) * i)))
		return (NULL);
	while (lst && j < i)
	{
		tmp = ft_strjoin(ft_strjoin(lst->key, "="), lst->value);
		tab[j] = ft_strdup(tmp);
		j++;
		lst = lst->next;
		free(tmp);
	}
	return(tab);
}

static void	run_cmd(char **cmd, t_env * lst)
{
	pid_t	father;
	char	**tab;

	father = fork();
	if (father)
		wait(NULL);
	else
		execve(cmd[0], cmd, (tab = build_env_tab(lst)));
}

int run_builtins(char **cmd, t_env *lst)
{
	static	t_builtins	builtins[] = {
							{"cd", ft_cd},
							{"exit", ft_exit},
							{"env", ft_env},
							{"setenv", ft_setenv},
							{"unsetenv", ft_unsetenv},
							{"setprompt", ft_setprompt},
							{"echo", ft_echo}};
	int i;

	i = 0;
	while (i < 7)
	{
		if (!ft_strcmp(cmd[0], builtins[i].name))
		{
			// ft_printf("%s    %s \n", cmd[0], builtins[i].name);
			builtins[i].func(&cmd[0], lst);
			return (1);
		}
		i++;
	}
	return (0);
}

int run_file(char **cmd, t_env *lst)
{
	if (cmd[0][0] != '.' && cmd[0][0] != '/')
		return (0);
	if (access(*cmd, F_OK) == -1)
		print_error("minishell: ", "no such file or directory: ", cmd[0]);
	if (access(*cmd, X_OK) == -1)
		print_error("minishell: ", "permission denied: ", cmd[0]);
	else
		run_cmd(cmd, lst);
	return (1);
}

char **parse_and_split(char **cmd, t_env *lst)
{
	char **tab;
	char **tmp;
	int i;

	i = 0;
	if (!cmd)
		return (NULL);
	if ((tab = ft_strsplit(*cmd, ';')))
	{
		while (tab && tab[i] && g_running)
		{
			tmp = ft_strsplit(tab[i], ' ');
			if (!(run_file(tmp, lst)) && !(run_builtins(tmp, lst)))
				run_cmd(tmp, lst);
			i++;
		}
	}
	return (tab);
}

void print_prompt(t_env *lst)
{
	t_env *tmp;

	if (!lst)
		g_running = 0;
	if ((tmp = lst_search_env("PROMPT", lst)))
		ft_putstr(tmp->value);
	else
		ft_putstr("<3");
}

void ft_start(t_env *lst)
{
	char *cmd;

	while (g_running)
	{	
		// print_prompt(lst);
		ft_putstr("$>"); // print prompt
		get_next_line(0, &cmd);
		// exec_cmd(&cmd, lst);
		parse_and_split(&cmd, lst);
		//parser cmd en un tableau
		// 1 parser le ; 
		// 2 parser les opt du 1
		// run_file(cmd, lst);
		// if (!run_file(cmd, lst) && !run_builtins(cmd, lst))
		// 	run_path(cmd, lst);
		// run_cmd(cmd, lst);
		// 	ft_printf("%s=%s %d\n", lst->key, lst->value, lst->size);
		ft_memdel((void **)&cmd);
	}
}


int main(int argc, char *argv[], char *env[])
{
	t_env *lst;


	lst = do_the_dope_walk(env, lst);
	ft_start(lst);
	signal(SIGINT, sig_handler);	
	// ft_end(lst);
	return(0);
}