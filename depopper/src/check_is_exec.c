/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:48:13 by aschafer          #+#    #+#             */
/*   Updated: 2016/03/20 20:30:47 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		try_path(char *path)
{
	if (!access(path, F_OK))
	{
		if (!access(path, X_OK))
			return (1);
		error("minishell: access denied:", path);
		return (-1);
	}
	return (0);
}

static void		norm_path(char **tab, char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (tab[i])
	{
		tmp = tab[i];
		tab[i] = ft_strjoin(tab[i], str);
		free(tmp);
		i++;
	}
}

static char		*try_full_path(char *exec, int i, int ret)
{
	char	*tmp;
	char	**all;

	if (!(all = ft_strsplit(lst_get_value("PATH"), ':')))
		return (NULL);
	norm_path(all, "/");
	norm_path(all, exec);
	while (all[i])
	{
		ret = try_path(all[i]);
		if (ret)
		{
			tmp = ft_strdup(all[i]);
			free_tab_ptr(&all);
			return (tmp);
		}
		else if (ret == -1)
		{
			free_tab_ptr(&all);
			return (NULL);
		}
		i++;
	}
	free_tab_ptr(&all);
	return (NULL);
}

static int		try_path_dir(char *path)
{
	struct stat lol;

	stat(path, &lol);
	if (S_ISDIR(lol.st_mode))
		return (1);
	return (0);
}

char			*check_is_exec(char **av)
{
	char	*full_path;
	int		ret;
	int		ret2;
	int		i;

	ret2 = 0;
	i = 0;
	if (!try_path_dir(av[0]))
	{
		ret = try_path(av[0]);
		if (ret == 1)
			return (ft_strdup(av[0]));
		else if (ret == -1)
			return (NULL);
		full_path = try_full_path(av[0], i, ret2);
		if (full_path)
			return (full_path);
	}
	error("minishell: command not found: ", av[0]);
	return (NULL);
}
