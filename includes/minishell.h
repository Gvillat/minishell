/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:11:29 by guvillat          #+#    #+#             */
/*   Updated: 2019/04/01 13:11:43 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdlib.h>
# include "../lib/includes/libft.h"
# include "../lib/includes/ft_printf.h"
# include <sys/stat.h>

int g_running;
int g_ret;

typedef struct s_env	t_env;
struct				s_env
{
	char			*key;
	void			*value;
	size_t			size;
	t_env			*next;
	t_env			*prev;
};

t_env *g_lst;

typedef struct		s_builtins
{
	char			*name;
	t_env			*(*func)(char **args, t_env *lst);
}					t_builtins;
void		ft_free_tab(char **tab);
void ft_free_lst(t_env *lst);
t_env 				*ft_exit(char **args, t_env *lst);
t_env 				*ft_env(char **args, t_env *lst);
t_env 				*ft_setenv(char **args, t_env *lst);
t_env 				*ft_unsetenv(char **args, t_env *lst);
t_env 				*ft_echo(char **args, t_env *lst);
t_env 				*ft_cd(char **args, t_env *lst);
void				free_lst(t_env *lst);
t_env				*build_lst_env(char **env, t_env *lst);
char				**build_env_tab(t_env *lst);
t_env				*lst_del_env(char *name, t_env *lst);
t_env				*lst_add_env(char **tmp, t_env *lst);
t_env				*lst_search_env(char *name, t_env *lst);
t_env				*lst_add_lvl(t_env *lst);
t_env				*parse_tok(char *line, t_env *lst);
int 				print_error(char *from, char *str1, char *str2);
int					run_path(char **cmd, t_env **lst);
int					run_cmd(char **cmd, t_env **lst);
int					run_builtins(char **cmd, t_env **lst);
int					run_file(char **cmd, t_env **lst);
t_env 				*build_no_env();


#endif