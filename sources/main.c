#include "../includes/minishell.h"
// #include "../libs/libft/get_next_line.h"

int main(int argc, char *argv[], char *env[])
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (!env)
		exit(0);
	else
	{
		while (42)
		{	
			ft_printf("$>\n");
			get_next_line(1, argv);
			// ft_strsplit(argv, )
			while (env[i])
			{
				ft_printf("%s\n",env[i]);
				i++;
			}
		}
	}
	return(0);
}
