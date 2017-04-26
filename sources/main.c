#include "../includes/minishell.h"
#include <stdio.h>
// #include "../libs/libft/get_next_line.h"

t_env *ft_new_env(char **name, t_env *lst)
{
	t_env *new;
	size_t size;

	if (!lst)
		size = 0;
	else
		size = lst->size;
	if (!(new = (t_env*)malloc(sizeof(t_env))))
		return(NULL);
	new->key = name[0];
	new->value = name[1];
	new->size = size + 1;
	new->next = NULL;
	new->prev = lst;
	return (new);
}

t_env *ft_add_env(char **tmp, t_env *lst)
{
	// ft_printf("%s=%s\n", tmp[0], tmp[1]);
	if(!lst)
		return (lst = ft_new_env(tmp, NULL));
	while (lst->next)
		lst = lst->next;
	return (lst->next = ft_new_env(tmp, lst));
}

t_env *do_the_dope_walk(char *env, t_env *lst)
{
	char **tmp;

	if (!env)
		return (NULL);
	tmp = ft_strsplit(env, '=');
	lst = ft_add_env(tmp, lst);
	return (lst);
}

char **ft_get_path(t_env **lst)
{
	t_env *tmp;
	char **tt;
	int i;

	i = 0;
	tt= NULL;
	tmp = *lst;
	while(tmp && ft_strcmp(tmp->key, "PATH"))
		tmp = tmp->prev;
	tt = ft_strsplit(tmp->value, ':');
	return (tt);
}

int main(int argc, char *argv[], char *env[])
{
	int i;
	t_env *lst;
	char **path;

	lst = NULL;
	i = 0;
	if (!env)
		exit(0);
	else
	{
		while (42)
		{	
			ft_putstr("$>");
			get_next_line(1, argv);
			while (env[i])
			{
				lst = do_the_dope_walk(env[i], lst);
				ft_printf("%s=%s\n",lst->key, lst->value );
				i++;
			}
			i = 0;
			path = ft_get_path(&lst);
			while (path[++i])
				ft_printf("%s\n", path[i]);
		}
	}
	return(0);
}
