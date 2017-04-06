/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_setprompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 14:50:32 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/20 21:00:41 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "minishell.h"
#define CDEF "\033[00m"
#define CG "\033[32m"

void	bi_setprompt(char **args)
{
	char *str;
	char *parsed;

	(void)args;
	ft_putstr("Enter new prompt: ");
	if (get_next_line(0, &str) != 1)
		return ;
	parsed = parse_vars(str);
	hash_set(&g_env, "MSP", parsed, ft_strlen(parsed) + 1);
	ft_putstr(CG);
	ft_putstr("Prompt set successfully !");
	ft_putendl(CDEF);
	free(str);
}
