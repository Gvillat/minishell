/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:41:28 by guvillat          #+#    #+#             */
/*   Updated: 2018/11/09 13:42:17 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		len;
	int		j;
	char	**tab;

	if (!(char*)s)
		return (NULL);
	if (!(tab = ft_memalloc(sizeof(tab) * (ft_countwords(s, c) + 1))))
		return (NULL);
	i = 0;
	len = 0;
	j = 0;
	while (s[i])
	{
		while (s[i + len] && s[i + len] != c)
			len++;
		if (len)
			tab[j++] = ft_strsub(s, i, len);
		i += len ? len : 1;
		len = 0;
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_strsplitif(char const *s, char c)
{
	int		i;
	int		len;
	int		j;
	char	**tab;

	if (!(char*)s || !ft_isescaped((char)&s))
		return (NULL);
	if (!(tab = ft_memalloc(sizeof(tab) * (ft_countwords(s, c) + 1))))
		return (NULL);
	i = 0;
	len = 0;
	j = 0;
	while (s[i])
	{
		while (s[i + len] && s[i + len] != c)
			len++;
		if (len)
			tab[j++] = ft_strsub(s, i, len);
		i += len ? len : 1;
		len = 0;
	}
	tab[j] = NULL;
	return (tab);
}
