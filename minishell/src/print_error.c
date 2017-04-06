/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 13:48:30 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/19 18:26:17 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error(char *from, char *str1, char *str2)
{
	ft_putstr_fd(from, 2);
	if (str1)
		ft_putstr_fd(str1, 2);
	if (str2)
		ft_putendl_fd(str2, 2);
}
