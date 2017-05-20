#include "../includes/minishell.h"

t_env *lst_del_env(char *name, t_env *lst)
{
	t_env *tmp;

	tmp = NULL;
	if (!(lst = lst_search_env(name, lst)))
		print_error("unsetenv: variable introuvable", "", "");
	else
	{
		if (lst->prev)
			lst->prev->next = lst->next;
		if (lst->next)
			lst->next->prev = lst->prev;
		tmp = lst;
		if (!lst->prev)
			lst = lst->next;
		else
			lst = lst->prev;
		free(tmp);
	}
	return (lst);
}

static t_env *lst_new_env(char **name, t_env *lst)
{
	t_env *new;
	size_t size;

	if (!(new = (t_env*)malloc(sizeof(t_env))))
		return(NULL);
	if (!lst)
		size = -1;
	else
	{
		size = lst->size;
	}
	new->key = name[0];
	new->value = name[1];
	new->size = size + 1;
	new->next = NULL;
	new->prev = lst;
	return (new);
}

t_env *lst_add_env(char **tmp, t_env *lst)
{
	t_env *tt;

	if(!lst)
		return (lst = lst_new_env(tmp, NULL));
	tt = lst;
	while (tt->next)
		tt = tt->next;
	tt->next = lst_new_env(tmp, tt);
	return (lst);
}

t_env *lst_search_env(char *name, t_env *lst)
{
	t_env *tmp;

	if (!name || !lst)
		return (NULL);
	tmp = lst;
	while (tmp)
	{
		if (ft_strequ(name, tmp->key))
		{
			return(tmp);
		}
		tmp = tmp->next;
	}
	return (tmp);
}

t_env *lst_add_lvl(t_env *lst)
{
	t_env *tmp;
	int		i;

	tmp = lst;
	tmp = lst_search_env("SHLVL", tmp);
	i = ft_atoi(tmp->value);
	++i;
	tmp->value = ft_itoa(i);
	return (lst);
}