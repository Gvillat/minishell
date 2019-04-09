/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:32:40 by guvillat          #+#    #+#             */
/*   Updated: 2018/11/09 13:34:07 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	size_t			slen;
	size_t			dlen;

	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	i = 0;
	if (size <= dlen)
		return (slen + size);
	while (dst[i] && i < size - 1)
		i++;
	while (i < size - 1 && *src)
		dst[i++] = *src++;
	dst[i] = '\0';
	return (slen + dlen);
}
