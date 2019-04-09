/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:39:37 by guvillat          #+#    #+#             */
/*   Updated: 2018/11/09 13:40:02 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strnew(size_t size)
{
	char	*text;

	if (!(text = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	ft_memset(text, '\0', size + 1);
	return (text);
}
