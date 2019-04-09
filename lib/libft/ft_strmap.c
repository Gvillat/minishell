/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:35:06 by guvillat          #+#    #+#             */
/*   Updated: 2018/11/09 13:35:57 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	if (!(char*)s)
		return (NULL);
	i = 0;
	if (!(str = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (*s)
		str[i++] = (*f)(*s++);
	return (str);
}
