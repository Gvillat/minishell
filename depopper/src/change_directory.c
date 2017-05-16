/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 22:46:58 by aschafer          #+#    #+#             */
/*   Updated: 2016/03/20 19:44:06 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*get_curr_directory(void)
{
	char curr_dir[1000];

	if (!getcwd(curr_dir, 1000))
		return (NULL);
	return (ft_strdup(curr_dir));
}

static void	go_to(char *path)
{
	char *new_path;

	new_path = ft_strdup(path);
	if (access(path, F_OK) != -1)
	{
		if (access(path, R_OK) == -1)
			error("Cd: permission denied: ", path);
		else
		{
			if (g_inf->oldpwd)
				free(g_inf->oldpwd);
			g_inf->oldpwd = get_curr_directory();
			lst_change_value("OLDPWD", get_curr_directory());
			chdir(new_path);
			lst_change_value("PWD", get_curr_directory());
		}
	}
	else
		error("Cd: path not found: ", path);
	ft_memdel((void**)&new_path);
}

static void	check_path(char *path)
{
	char	*var;
	char	*new;
	int		ret;

	new = NULL;
	var = ft_strnew(700);
	ret = check_is_variable(path, var, &new);
	if (path[0] == '-' && !path[1])
		go_to(g_inf->oldpwd);
	else if (path[0] == '~')
	{
		new = ft_strjoin(g_inf->home, path + 1);
		go_to(new);
	}
	else if (ret != -1)
		go_to(!ret ? new : path);
	if (new)
		free(new);
	free(var);
	return ;
}

void		change_directory(char **entry)
{
	int i;

	i = 0;
	while (entry[i])
		i++;
	if (i < 2)
		check_path("$HOME");
	else
		check_path(entry[1]);
}
