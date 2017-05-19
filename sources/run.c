#include "../includes/minishell.h"

static int finding_path(char **path, char **cmd, t_env **lst)
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

void run_path(char **cmd, t_env **lst)
{
	t_env *curr;
	char **path;

	curr = lst_search_env("PATH", *lst);
	path = ft_strsplit(curr->value, ':');
	finding_path(path, cmd, lst);
	free(path);
}

void	run_cmd(char **cmd, t_env **lst)
{
	pid_t	father;
	char	**tab;

	father = fork();
	if (father)
		wait(NULL);
	else
		execve(cmd[0], cmd, (tab = build_env_tab(*lst)));
}

int run_builtins(char **cmd, t_env **lst)
{
	static	t_builtins	builtins[] = {
							{"cd", ft_cd},
							{"exit", ft_exit},
							{"env", ft_env},
							{"setenv", ft_setenv},
							{"unsetenv", ft_unsetenv},
							{"echo", ft_echo}};
	int i;

	i = 0;
	while (i < 6)
	{
		if (!ft_strcmp(cmd[0], builtins[i].name))
		{
			*lst = builtins[i].func(&cmd[0], *lst);
			return (1);
		}
		i++;
	}
	return (0);
}

int run_file(char **cmd, t_env **lst)
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