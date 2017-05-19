#include "../includes/minishell.h"

static t_env *climb_the_ladder(t_env *lst)
{
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

char **parse_and_exec(char **cmd, t_env **lst)
{
	char **tab;
	char **tmp;
	int i;

	i = 0;
	if (!cmd)
		return (NULL);
	if ((tab = ft_strsplit(*cmd, ';')))
	{
		while (tab && tab[i] && g_running)
		{
			tmp = ft_strsplit(tab[i], ' ');
			if (!(run_file(tmp, lst)) && !(run_builtins(tmp, lst)))
				run_path(tmp, lst);
			i++;
		}
	}
	if ((*lst)->prev)
		*lst = climb_the_ladder(*lst);
	return (tab);
}
