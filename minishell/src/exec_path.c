/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 13:11:42 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/20 17:26:09 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"

char	*build_path(char *path, char *name)
{
	static char buffer[500];

	ft_memset(buffer, 0, 500);
	ft_strcat(buffer, path);
	ft_strcat(buffer, "/");
	ft_strcat(buffer, name);
	return (buffer);
}

void	exec_path(char **cmd)
{
	int		i;
	char	**paths;
	char	*path;

	if (!(paths = ft_strsplit(hash_get(g_env, "PATH", TRUE), ':')))
		return (print_error("minishell: ", CNOT_FOUND, cmd[0]));
	i = 0;
	while (paths[i])
	{
		path = build_path(paths[i++], cmd[0]);
		if (!access(path, F_OK))
		{
			free(cmd[0]);
			cmd[0] = ft_strdup(path);
			exec_file(cmd);
			return ;
		}
	}
	ft_freetab((void **)paths);
	print_error("minishell: ", CNOT_FOUND, cmd[0]);
}
