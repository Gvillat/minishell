/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:38:15 by guvillat          #+#    #+#             */
/*   Updated: 2018/11/09 11:39:23 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_countwords(char const *s1, char c)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (s1[i])
	{
		if ((i == 0 && s1[i] != c) ||
				(i != 0 && s1[i] != c && s1[i - 1] == c))
			ret++;
		i++;
	}
	return (ret);
}
