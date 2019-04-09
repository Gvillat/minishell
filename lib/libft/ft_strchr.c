/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:24:46 by guvillat          #+#    #+#             */
/*   Updated: 2018/11/09 13:25:05 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (c == '\0')
	{
		i = ft_strlen(s);
		return ((char *)&(s[i]));
	}
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&(s[i]));
		else
			i++;
	}
	return (NULL);
}
