/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:07:21 by guvillat          #+#    #+#             */
/*   Updated: 2019/04/01 13:07:22 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	finding_path(char **path, char **cmd, t_env **lst)
{
	int		i;
	char	*tmp[2];

	tmp[0] = NULL;
	tmp[1] = NULL;
	i = 0;
	while (path[i])
	{
		tmp[0] = ft_strjoin(path[i], "/");
		tmp[1] = ft_strjoin(tmp[0], cmd[0]);
		free(tmp[0]);
		if (access(tmp[1], F_OK) == 0)
		{
			free(cmd[0]);
			cmd[0] = ft_strsub(tmp[1], 0, ft_strlen(tmp[1]) + 1);
			run_cmd(&cmd[0], lst);
			free(tmp[1]);
			return (1);
		}
		free(tmp[1]);
		i++;
	}
	return (0);
}	

int		run_path(char **cmd, t_env **lst)
{
	t_env	*curr;
	char	**path;
	int 	ret;

	curr = NULL;
	ret = 0;
	if ((curr = lst_search_env("PATH", *lst)) && curr)
	{
		if ((path = ft_strsplit(curr->value, ":")))
		{
			ret = finding_path(path, cmd, lst);
			ft_free_tab(path);
		}
	}
	return (ret);
}


void ft_exec_ret(pid_t cpid)
{
	pid_t w;
	int status;

    w = waitpid(cpid, &status, WUNTRACED | WCONTINUED);
    if (w == -1)
    {
		ft_printf("waitpid: failed");
        exit(0);
    }
    if (WIFEXITED(status))
		g_ret = WEXITSTATUS(status);
    else if (WIFSIGNALED(status))
		ft_printf("tué par le signal %d\n", WTERMSIG(status));
    else if (WIFSTOPPED(status))
		ft_printf("arrêté par le signal %d\n", WSTOPSIG(status));
    else if (WIFCONTINUED(status))
        ft_printf("relancé\n");
}

int			run_cmd(char **cmd, t_env **lst)
{
	pid_t	father;
	char	**tab;

	tab = NULL;
	father = fork();
	if (father == -1)
	{
		print_error("fork: ", "failed", "");
        exit(0);
    }
	if (father)
		ft_exec_ret(father);
	else
	{
		tab = build_env_tab(*lst);
		g_ret = execve(cmd[0], cmd, tab);
		ft_free_tab(tab);
		ft_free_lst(*lst);
		exit (1);
	}
	return (0);
}

int			run_builtins(char **cmd, t_env **lst)
{
	static	t_builtins	builtins[] = {
							{"cd", ft_cd},
							{"exit", ft_exit},
							{"env", ft_env},
							{"setenv", ft_setenv},
							{"unsetenv", ft_unsetenv},
							{"echo", ft_echo}};
	int					i;

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

int			run_file(char **cmd, t_env **lst)
{
	if (cmd[0][0] != '.' && cmd[0][0] != '/')
		return (0);
	if (access(*cmd, F_OK) == -1)
		print_error("minishell: ", "no such file or directory: ", cmd[0]);
	else if (access(*cmd, X_OK) == -1)
		print_error("minishell: ", "permission denied: ", cmd[0]);
	else
		run_cmd(cmd, lst);
	return (1);
}