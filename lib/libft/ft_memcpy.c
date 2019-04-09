/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:00:58 by guvillat          #+#    #+#             */
/*   Updated: 2018/11/09 12:02:06 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	const char		*from;
	char			*to;

	from = src;
	to = dest;
	i = 0;
	while (i++ < n)
		*(to++) = *(from++);
	return (dest);
}
