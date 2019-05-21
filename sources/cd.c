
static t_env	*go_to(char *path, t_env *lst)
{
	static struct stat	st;
	char				*str;

	if (access(path, F_OK) == -1)
		return (print_error("cd: ", "no such file or directory: ", path, lst));
	if (stat(path, &st) == -1)
		return (print_error("cd: ", "stat error: ", path, lst));
	if (!(S_ISDIR(st.st_mode)))
		return (print_error("cd: ", "not a directory: ", path, lst));
	if (access(path, R_OK) == -1)
		return (print_error("cd: ", "permission denied: ", path, lst));
	if ((lst = lst_search_env("PWD", lst)))
	{
		str = lst->value;
		if (!chdir(path))
		{
			path = getcwd(NULL, 0);
			lst->value = path;
		}
	}
	if ((lst = lst_search_env("OLDPWD", lst)))
		lst->value = str;
	return (lst);
}

t_env			*ft_cd(char **args, t_env *lst)
{
	int		i;

	if (!lst_search_env("HOME", lst))
	{
		ft_printf("minishell: cd: HOME not set\n");
		return (lst);
	}
	if (ft_strequ(args[0], "cd") && !args[1] && lst_search_env("HOME", lst))
		go_to(lst_search_env("HOME", lst)->value, lst);
	i = 0;
	while (args[++i])
	{
		if (ft_strequ(args[i], "-") && lst_search_env("OLDPWD", lst))
			go_to(lst_search_env("OLDPWD", lst)->value, lst);
		// else if (args[i][0] == '~')
		// 	ft_tilted(args[i], lst);
		else
			go_to(args[i], lst);
	}
	return (lst);
}