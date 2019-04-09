/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:09:21 by guvillat          #+#    #+#             */
/*   Updated: 2018/11/09 13:58:01 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*p_dst;

	p_dst = dst;
	if (dst < src)
		while ((size_t)(dst - p_dst) < len)
			*(char*)dst++ = *(char*)src++;
	else
		while (len-- > 0)
			((char*)dst)[len] = ((char*)src)[len];
	return (p_dst);
}
