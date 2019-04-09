/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:44:10 by guvillat          #+#    #+#             */
/*   Updated: 2018/11/09 13:45:09 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strtrim(char const *s)
{
	unsigned int		start;
	int					end;

	start = 0;
	if (s)
		end = (int)ft_strlen(s) - 1;
	else
		return (NULL);
	while ((s[start] == ' ' || s[start] == '\t' || s[start] == '\n') &&
			s[start])
		start++;
	while ((s[end] == ' ' || s[end] == '\t' || s[end] == '\n') && s[end] &&
			(unsigned int)end > start)
		end--;
	if ((unsigned int)end <= start)
		return (ft_strnew(1));
	return (ft_strsub(s, start, (end - start + 1)));
}
