#include "../includes/minishell.h"

t_env *ft_cd(char **args, t_env *lst)
{
	int i;

	// if (!args[0])
		// return (go_to(hash_getset(&g_env, "HOME", "/", 2)->value));
	i = 0;
	while (args[i])
	{
// 		go_to(args[i]);
		++i;
	}
	return (lst);
}