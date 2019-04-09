/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:57:48 by guvillat          #+#    #+#             */
/*   Updated: 2018/11/09 11:59:04 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *pdst;
	unsigned char *psrc;

	psrc = (unsigned char*)src;
	pdst = (unsigned char*)dst;
	while (n--)
	{
		*pdst++ = *psrc;
		if (*psrc++ == (unsigned char)c)
			return (pdst);
	}
	return (NULL);
}
