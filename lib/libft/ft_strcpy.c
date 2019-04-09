/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:26:45 by guvillat          #+#    #+#             */
/*   Updated: 2018/11/09 13:28:40 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char *pdst;

	pdst = dst;
	while (*src)
		*pdst++ = *src++;
	*pdst = '\0';
	return (dst);
}
