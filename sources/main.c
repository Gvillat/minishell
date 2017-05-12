#include "../includes/minishell.h"
#include <stdio.h>

int	g_process_running = 0;
int g_running = 1;

void	print_error(char *from, char *str1, char *str2)
{
	ft_putstr_fd(from, 2);
	if (str1)
		ft_putstr_fd(str1, 2);
	if (str2)
		ft_putendl_fd(str2, 2);
}


t_env *ft_new_env(char **name, t_env *lst)
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

t_env *ft_add_env(char **tmp, t_env *lst)
{
	if(!lst)
		return (lst = ft_new_env(tmp, NULL));
	while (lst->next)
		lst = lst->next;
	return (lst->next = ft_new_env(tmp, lst));
}

t_env *ft_search_env(char *str, t_env *lst)
{
	int i;

	i = 0;
	if (!lst)
		return(NULL);
	else
	{
		
	}
	return (lst);
}

static void ft_add_lvl(t_env *lst)
{
	int		i;

	while(!ft_strequ("SHLVL", lst->key))
		lst = lst->prev;
	i = ft_atoi(lst->value);
	++i;
	lst->value = ft_itoa(i);

}

t_env *do_the_dope_walk(char **env, t_env *lst)
{
	char **tmp;
	int i;
	// char *prpt[2];
	
	// prpt[0] = "PROMPT";
	// prpt[1] = "$>";
	i = 0;
	lst = NULL;
	while (env[i])
	{
		tmp = ft_strsplit(env[i], '=');
		lst = ft_add_env(tmp, lst);
		i++;
		free(tmp);
	}
	// lst = ft_add_env(prpt, lst);
	return (lst);
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
	while (lst && lst->prev)
		lst = lst->prev;
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

static void	run_cmd(char *cmd, t_env * lst)
{
	pid_t	father;
	char	**tab;
	char 	**bb;

	if (!(bb = (char**)ft_memalloc(sizeof(char*) * 3)))
		exit(0);
	father = fork();
	if (father)
	{
		g_process_running = 1;
		wait(NULL);
		g_process_running = 0;
	}
	else
	{
		execve(cmd, bb, (tab = build_env_tab(lst)));
	}
}

char **parse_and_split(char **cmd)
{
	char *tmp;
	char **tab;
	int i;

	i = -1;
	if (!cmd)
		return (NULL);
	if ((tab = ft_strsplit(*cmd, ' ')))
	{
		while (tab[++i])
		{
			tab[i] = ft_strtrim(tab[i]);
			ft_printf("%s\n", tab[i])
		}
	}



	return (tab);
}

// void exec_cmd(char **cmd, t_env *env)
// {
// 	char **tab;

// 	tab = parse_and_split(cmd);

// }

// int run_file(char *cmd, t_env *lst)
// {
// 	if (cmd[0] != '.' && cmd[0] != '/')
// 		return (0);
// 	if (access(cmd, F_OK) == -1)
// 		print_error("minishell: ", "no such file or directory: ", cmd);
// 	else if (access(cmd, X_OK) == -1)
// 		print_error("minishell: ", "permission denied: ", cmd);
// 	else
// 		run_cmd(cmd, lst);
	// return (1);
// }

int main(int argc, char *argv[], char *env[])
{
	t_env *lst;
	char *cmd;
	char **tab;
	int i;

	lst = do_the_dope_walk(env, lst);
	ft_add_lvl(lst);
	// signal(SIGINT, sig_handler);	
	while (g_running)
	{	
		ft_putstr("$>");
		get_next_line(0, &cmd);
		// exec_cmd(&cmd, lst);
		tab = parse_and_split(&cmd);
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
	return(0);
}