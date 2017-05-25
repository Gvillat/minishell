/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:54:25 by gvillat           #+#    #+#             */
/*   Updated: 2017/05/22 15:54:30 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "libft.h"
# include "get_next_line.h"
# include "fpf_printf.h"
# include <sys/stat.h>

int g_running;

typedef struct s_env	t_env;
struct				s_env
{
	char			*key;
	void			*value;
	size_t			size;
	t_env			*next;
	t_env			*prev;
};

typedef struct		s_builtins
{
	char			*name;
	t_env			*(*func)(char **args, t_env *lst);
}					t_builtins;

t_env				*ft_exit(char **args, t_env *lst);
t_env				*ft_env(char **args, t_env *lst);
t_env				*ft_setenv(char **args, t_env *lst);
t_env				*ft_unsetenv(char **args, t_env *lst);
t_env				*ft_echo(char **args, t_env *lst);
t_env				*ft_cd(char **args, t_env *lst);
void				free_lst(t_env *lst);
t_env				*build_lst_env(char **env, t_env *lst);
char				**build_env_tab(t_env *lst);
t_env				*lst_del_env(char *name, t_env *lst);
t_env				*lst_add_env(char **tmp, t_env *lst);
t_env				*lst_search_env(char *name, t_env *lst);
t_env				*lst_add_lvl(t_env *lst);
char				**parse_and_exec(char **cmd, t_env **lst);
void				print_error(char *from, char *str1, char *str2);
void				run_path(char **cmd, t_env **lst);
void				run_cmd(char **cmd, t_env **lst);
int					run_builtins(char **cmd, t_env **lst);
int					run_file(char **cmd, t_env **lst);

#endif
