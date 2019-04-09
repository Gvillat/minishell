/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:40:36 by guvillat          #+#    #+#             */
/*   Updated: 2018/11/09 13:41:02 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strrchr(const char *s, int c)
{
	int len;

	len = ft_strlen((char*)s);
	s += len;
	while (len > -1)
	{
		if (*s == c)
			return ((char*)s);
		len--;
		s--;
	}
	return (NULL);
}
