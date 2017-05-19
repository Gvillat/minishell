#include "../includes/minishell.h"
#include <stdio.h>

t_env *ft_cd(char **args, t_env *lst)
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
	return (lst);
}

t_env *ft_exit(char **args, t_env *lst)
{
	g_running = 0;
	return (free_lst(&lst));
}

t_env *ft_env(char **args, t_env *lst)
{
	t_env *tmp;
	if (!lst)
		print_error("unsetenv: variable introuvable", "chibre", "");
	tmp  = lst;
	while (tmp)
	{
		ft_printf("%s=%s %d\n", tmp->key, tmp->value, tmp->size);
		tmp = tmp->next;
	}
	return (lst);
}

t_env *ft_setenv(char **args, t_env *lst)
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
	return (lst);
}

t_env *ft_unsetenv(char **args, t_env *lst)
{
	if (!args[1])
		print_error("Usage: unsetenv 'variable'", "", "");
	else
		lst = lst_del_env(args[1], lst);
	return (lst);
}

t_env *ft_echo(char **args, t_env *lst)
{
	int i;

	i = 1;
	while (args[i])
	{	
		ft_printf("%s ", args[i]);
		i++;
	}
	ft_putchar('\n');
	return (lst);
}


int finding_path(char **path, char **cmd, t_env **lst)
{
	int i;
	char *tmp;

	tmp = NULL;
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(ft_strjoin(path[i], "/"), cmd[0]);
		if (access(tmp, F_OK) == 0)
		{	
			cmd[0] = ft_strsub(tmp, 0, ft_strlen(tmp) + 1);
			run_cmd(cmd, lst);
			free(tmp);
			return (1);
		}
		free(tmp);
		i++;
	}
	return (0);
}
