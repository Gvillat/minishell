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

static size_t	ft_countwords(const char *s, char *c)
{
	size_t	n_words;

	n_words = 0;
	while (*s)
	{
		if (ft_strchr(c, *s))
			s++;
		else
		{
			while (!(ft_strchr(c, *s)) && *s)
				s++;
			n_words++;
		}
	}
	return (n_words);
}

char			**ft_strsplit(const char *s, char *c)
{
	size_t	i;
	size_t	len;
	size_t	j;
	char	**tab;

	i = 0;
	j = 0;
	len = 0;
	if (!c || !s)
		return (NULL);
	if (!(tab = ft_memalloc(sizeof(tab) * (ft_countwords(s, c) + 1))))
		return (NULL);
	if (!tab)
		return (NULL);
	while (s[i])
	{
		while (s[i + len] && !(ft_strchr(c, s[i + len])))
			len++;
		if (len)
		{
			tab[j] = ft_strsub(s, i, len);
			j++;
		}
		i += len ? len : 1;
		len = 0;
	}
	tab[j] = NULL;
	return (tab);
}
