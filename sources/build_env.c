#include "../includes/minishell.h"

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
		ft_memdel((void**)tmp);
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