/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:59:14 by guvillat          #+#    #+#             */
/*   Updated: 2018/11/09 11:59:47 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	d;
	unsigned char	*s2;
	int				i;

	i = 0;
	s2 = (unsigned char *)s;
	d = c;
	while (n--)
	{
		if (s2[i] == d)
			return (&(s2[i]));
		i++;
	}
	return (NULL);
}
