#include "../includes/minishell.h"

static void	go_to(char *path, t_env *lst)
{
	static struct stat st;
	char *str;

	if (access(path, F_OK) == -1)
		return (print_error("cd: ", "no such file or directory: ", path));
	if (stat(path, &st) == -1)
		return (print_error("cd: ", "stat error: ", path));
	if (!(S_ISDIR(st.st_mode)))
		return (print_error("cd: ", "not a directory: ", path));
	if (access(path, R_OK) == -1)
		return (print_error("cd: ", "permission denied: ", path));
	lst = lst_search_env("PWD", lst);
	str = lst->value;
	chdir(path);
	lst->value = path;
	lst = lst_search_env("OLDPWD", lst);
	lst->value = str;
}

t_env	*ft_cd(char **args, t_env *lst)
{
	int i;
	char buf[4096];

	ft_memset(buf, 0, 4096);
	if (ft_strequ(args[0], "cd") && !args[1])
		go_to(lst_search_env("HOME", lst)->value, lst);
	i = 0;
	while (args[++i])
	{
		if (ft_strequ(args[i], "-"))
			go_to(lst_search_env("OLDPWD", lst)->value, lst);
		else if (args[i][0] == '~')
		{
			ft_strcat(buf, lst_search_env("HOME", lst)->value);
			ft_strcat(buf, args[i] + 1);
			args[i] = ft_strdup(buf);
			go_to(args[i], lst);
			free(buf);
		}
		else
			go_to(args[i], lst);
	}
	return(lst);
}

t_env *build_lst_env(char **env, t_env *lst)
{
	char **tmp;
	int i;
	char *prpt[2];
	
	prpt[0] = "PROMPT";
	prpt[1] = "$>";
	i = 0;
	lst = NULL;
	while (env[i])
	{
		tmp = ft_strsplit(env[i], '=');
		lst = lst_add_env(tmp, lst);
		i++;
		free(tmp);
	}
	lst_add_env(prpt, lst);
	return (lst_add_lvl(lst));
}

char **build_env_tab(t_env *lst)
{
	int i;
	int j;
	char **tab;
	char *tmp;

	i = lst->size + 1;
	j = 0;
	if (!(tab = (char**)ft_memalloc(sizeof(char *) * i)))
		return (NULL);
	while (lst && j < i)
	{
		tmp = ft_strjoin(ft_strjoin(lst->key, "="), lst->value);
		tab[j] = ft_strdup(tmp);
		j++;
		lst = lst->next;
		free(tmp);
	}
	return(tab);
}

void free_lst(t_env *lst)
{
	t_env *curr;

	while (lst)
	{
		curr = lst;
		free(curr);
		lst = lst->next;
	}
}