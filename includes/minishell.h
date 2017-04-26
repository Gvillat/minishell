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
	void			(*func)(char **args);
}					t_builtins;

void			ft_cd(char **args);
void			ft_exit(char **args);
void			ft_env(char **args);
void			ft_setenv(char **args);
void			ft_unsetenv(char **args);
void			ft_setprompt(char **args);

#endif