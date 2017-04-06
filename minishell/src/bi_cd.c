/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 18:04:18 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/20 14:38:21 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <unistd.h>
#include "minishell.h"

static BOOL	isdir(char *path)
{
	static struct stat entry;

	if (stat(path, &entry) == -1)
		return (FALSE);
	return (S_ISDIR(entry.st_mode));
}

static void	go_to(char *path)
{
	static char buf[4096];
	t_hash		*pwd;

	if (ft_strequ(path, "-"))
		return (go_to(hash_getset(&g_env, "OLDPWD", "/", 2)->value));
	ft_memset(buf, 0, 4096);
	if (path[0] == '~')
	{
		ft_strcat(buf, hash_getset(&g_env, "HOME", "/", 2)->value);
		ft_strcat(buf, path + 1);
		path = ft_strdup(buf);
		go_to(path);
		return (free(path));
	}
	if (access(path, F_OK) == -1)
		return (print_error("cd: ", FNOT_FOUND, path));
	if (!isdir(path))
		return (print_error("cd: ", "not a directory: ", path));
	if (access(path, R_OK) == -1)
		return (print_error("cd: ", FORBIDDEN, path));
	pwd = hash_getset(&g_env, "PWD", getcwd(buf, 4096), ft_strlen(buf) + 1);
	hash_set(&g_env, "OLDPWD", pwd->value, pwd->size);
	chdir(path);
	hash_set(&g_env, "PWD", getcwd(buf, 4096), ft_strlen(buf) + 1);
}

void		bi_cd(char **args)
{
	int i;

	if (!args[0])
		return (go_to(hash_getset(&g_env, "HOME", "/", 2)->value));
	i = 0;
	while (args[i])
	{
		go_to(args[i]);
		++i;
	}
}
