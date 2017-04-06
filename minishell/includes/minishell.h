/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:55:09 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/20 20:29:21 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"
# include "libhash.h"
# define NBBUILTINS 6
# define CNOT_FOUND "command not found: "
# define FNOT_FOUND "no such file or directory: "
# define FORBIDDEN "permission denied: "

extern t_hash	*g_env;
extern BOOL		g_process_running;
extern BOOL		g_running;

void			init_env(char **envp);
char			**build_env_tab(void);
void			print_error(char *form, char *str1, char *str2);
char			*parse_vars(char *str);
void			del_hash(void *value, size_t size);

/*
**	EXECS
*/

void			exec_cmd(char *str);
void			exec_path(char **cmd);
BOOL			exec_file(char **cmd);
BOOL			exec_builtin(char **cmd);

/*
**	BUILTINS
*/

typedef struct	s_builtins
{
	char	*name;
	void	(*func)(char **args);
}				t_builtins;

void			bi_cd(char **args);
void			bi_exit(char **args);
void			bi_env(char **args);
void			bi_setenv(char **args);
void			bi_unsetenv(char **args);
void			bi_setprompt(char **args);
#endif
