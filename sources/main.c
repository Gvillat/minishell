#include "../includes/minishell.h"
#include <stdio.h>

t_env *ft_new_env(char **name, t_env *lst)
{
	t_env *new;
	size_t size;

	if (!lst)
		size = 0;
	else
		size = lst->size;
	if (!(new = (t_env*)malloc(sizeof(t_env))))
		return(NULL);
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

t_env *do_the_dope_walk(char *env, t_env *lst)
{
	char **tmp;

	if (!env)
		return (NULL);
	tmp = ft_strsplit(env, '=');
	lst = ft_add_env(tmp, lst);
	return (lst);
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
			father = fork();
			execve(tmp, argv, env);
		}
		i++;
	}
	return (0);
}


// int ft_builtins(char **path, char **argv, t_env *lst, char **env)
// {
// 	static	t_builtins	builtins[] = {
// 								{"cd", ft_cd},
// 								{"exit", ft_exit},
// 								{"env", ft_env},
// 								{"setenv", ft_setenv},
// 								{"unsetenv", ft_unsetenv},
// 								{"setprompt", ft_setprompt},
// 								{"echo", ft_echo}};
// 	int i;

// 	i = 0;
// 	while (i < 6)
// 	{
// 		if (ft_strequ(argv[0], builtins[i].name))
// 		{
// 			ft_printf("%s    %s \n", argv[0], builtins[i].name);
// 			// builtins[i].func(argv + 1);
// 			return (1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

int main(int argc, char *argv[], char *env[])
{
	int i;
	t_env *lst;
	char **path;

	lst = NULL;
	i = 0;
	if (!env)
		exit(0);
	else
	{
		while (42)
		{	
			ft_putstr("$>");
			get_next_line(1, argv);
			while (env[i])
			{
				lst = do_the_dope_walk(env[i], lst);
				i++;
			}
			path = ft_get_path(&lst);
			// ft_builtins(path, argv, lst, env);
			finding_the_path(path, argv, lst, env);
			// else
			// 	build_built_built()
		}
	}
	return(0);
}
