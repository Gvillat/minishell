/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 23:50:30 by aschafer          #+#    #+#             */
/*   Updated: 2016/03/20 20:22:00 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define LE t_list_env
# define INF struct s_infos

# include <sys/types.h>
# include <sys/stat.h>
# include <uuid/uuid.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <pwd.h>

# include "libft.h"

typedef struct s_list_env	t_list_env;
struct						s_list_env
{
	char	*clef;
	char	*value;
	char	*string;
	LE		*next;
};

struct						s_infos
{
	char	**path;
	char	*oldpwd;
	char	*pwd;
	char	*user;
	char	*home;
	char	*string;
	int		ret;
	int		exittator;
	char	**arg;
	int		process;
};

typedef struct				s_builtins
{
	char	*name;
	void	(*built)(char **entry);
}							t_builtins;

extern INF					*g_inf;
extern LE					*g_lst;

/*
**** LISTES
*/
LE							*lst_new(char *string);
void						lst_push(LE **first, char *string);
void						lst_iter(LE **first, void (*f)(LE *entry));
LE							*lst_search(char *clef, LE **first);
int							lst_del_one(LE **first, char *entry);
void						lst_free(LE *curr);
void						lst_change_value(char *clef, char *new_val);
char						*lst_get_value(char *clef);
int							lst_get_size(LE **first);
int							check_is_variable(char *path, char *var,
							char **new);
/*
**** AUTRES
*/
void						fill_all(char **env_p);
void						free_tab_ptr(char ***tb);
int							read_entries();
void						print_prompt();
void						try_entry(char *entry);
int							check_is_builtins(char **entry);
void						error(char *erro, char *msg);
char						*check_is_exec(char **av);
char						**lst_to_tab(LE **lst);
void						chut(char **av, char **environ);
char						*get_curr_directory(void);
/*
**** BUILTINS
*/
void						print_env(char **ffff);
void						set_env(char **entry);
void						exit_prog(char **entry);
void						unset_env(char **entry);
void						change_directory(char **entry);
/*
**** SIGNAL
*/
void						signal_handler(int no);
/*
**** FREE
*/
void						free_all(LE **first);
#endif
