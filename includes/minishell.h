#ifndef MINISHELL_H
#define MINISHELL_H
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "../libs/libft/libft.h"
# include "../libs/libft/get_next_line.h"
# include "../libs/printf/includes/ft_printf.h"
# include <sys/stat.h>

int g_running;

typedef struct		s_env t_env;
struct 				s_env
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
	void			(*func)(char **args, t_env *lst);
}					t_builtins;

void			ft_cd(char **args, t_env *lst);
void			ft_exit(char **args, t_env *lst);
void			ft_env(char **args, t_env *lst);
void			ft_setenv(char **args, t_env *lst);
void			ft_unsetenv(char **args, t_env *lst);
void			ft_setprompt(char **args, t_env *lst);
void			ft_echo(char **args, t_env *lst);

t_env *lst_add_lvl(t_env *lst);
t_env *lst_add_env(char **tmp, t_env *lst);
t_env *lst_new_env(char **tmp, t_env *lst);
t_env *lst_search_env(char *tmp, t_env *lst);
t_env *lst_change_env(char *tmp, t_env *lst);
t_env *lst_remove_env(char *tmp, t_env *lst);
void print_prompt(t_env *lst);
void ft_start(t_env *lst);
#endif