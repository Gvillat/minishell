#include "../includes/minishell.h"
#include <stdio.h>

void ft_cd(char **args, t_env *lst)
{
	int i;

	// if (!args[0])
		// return (go_to(hash_getset(&g_env, "HOME", "/", 2)->value));
	i = 0;
	while (args[i])
	{
// 		go_to(args[i]);
		++i;
	}
}

void ft_exit(char **args, t_env *lst)
{
	g_running = 0;
}

void ft_env(char **args, t_env *lst)
{
	while (lst)
	{
		ft_printf("%s=%s\n", lst->key, lst->value);
		lst = lst->next;
	}
}

void ft_setenv(char **args, t_env *lst)
{
	char *arg[2];
	t_env *tmp;

	if (!args[1])
		ft_env(args, lst);
	else
	{
		arg[0] = args[1];
		arg[1] = args[2];
		if (!args[2])
			arg[1] = "(null)";
		if ((tmp = lst_search_env(arg[0], lst)))
			tmp->value = arg[1];
		else
			lst_add_env(arg, lst->next);
	}
}

void ft_unsetenv(char **args, t_env *lst)
{
	t_env *tmp;
	t_env *del;

	tmp = NULL;
	del = NULL;
	if (!args[1] || !lst)
		ft_start(lst);
 	if ((del = lst_search_env(args[1], lst)))
	{
		if (del->prev && del)
		{
			tmp = del->prev;
			tmp->next = del->next;
		}
		if (del->next && del)
		{
			del->next->prev = tmp;
		}
		free(del->prev);
		// ft_memdel((void**)del);
	}
}

void ft_echo(char **args, t_env *lst)
{
	int i;

	i = 1;
	while (args[i])
	{	
		ft_printf("%s ", args[i]);
		i++;
	}
	ft_putchar('\n');
}

void ft_setprompt(char **args, t_env *lst)
{
	printf("blablou\n");
}




char **ft_get_path(t_env **lst)
{
	t_env *tmp;
	char **tt;
	int i;

	i = 0;
	tt= NULL;
	tmp = *lst;
	while(tmp && ft_strcmp(tmp->key, "PATH"))
		tmp = tmp->prev;
	tt = ft_strsplit(tmp->value, ':');
	return (tt);
}







int finding_the_path(char **path, char **argv, t_env *lst, char **env)
{
	int i;
	char *tmp;
	pid_t father;

	tmp = NULL;
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		tmp = ft_strjoin(tmp, argv[0]);
		if (access(tmp, F_OK) == 0)
		{      
			// ft_printf("%s\n", tmp);                                                                                                                                                                                                                                                                                                         
			father = fork();
			execve(tmp, argv, env);
		}
		i++;
	}
	return (0);
}


// int ft_builtins(char **path, char **argv, t_env *lst, char **env)
// {
	// static	t_builtins	builtins[] = {
	// 							{"cd", ft_cd},
	// 							{"exit", ft_exit},
	// 							{"env", ft_env},
	// 							{"setenv", ft_setenv},
	// 							{"unsetenv", ft_unsetenv},
	// 							{"setprompt", ft_setprompt},
	// 							{"echo", ft_echo}};
	// int i;

	// i = 0;
	// while (i < 6)
	// {
	// 	if (ft_strequ(argv[0], builtins[i].name))
	// 	{
	// 		ft_printf("%s    %s \n", argv[0], builtins[i].name);
	// 		// builtins[i].func(argv + 1);
	// 		return (1);
	// 	}
	// 	i++;
	// }
	// return (0);
// }	