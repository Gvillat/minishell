/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:26:20 by guvillat          #+#    #+#             */
/*   Updated: 2018/11/09 13:26:36 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if (*s1 != *s2 || (*s1 == '\0' && *s2 == '\0'))
		return ((unsigned char)*s1 - (unsigned char)*s2);
	return (ft_strcmp(s1 + 1, s2 + 1));
}
