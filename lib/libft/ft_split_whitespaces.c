/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 19:22:17 by guvillat          #+#    #+#             */
/*   Updated: 2018/09/18 19:22:53 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int			ft_check_separator(char c)
{
	if (c == 32 || c == ' ' || c == 13)
		return (0);
	if (c == 9 || c == 11 || c == '\t')
		return (0);

	return (1);
}

static int		ft_strlenwp(char *str, int *index, int mod)
{
	int i;

	i = 0;
	while (str[i] && ft_check_separator(str[i]) == 1)
		i++;
	if (mod == 2)
		*index += 1;
	return (i);
}

static int			ft_count_words(char *str)
{
	int i;
	int ret;

	i = 1;
	ret = 0;
	if (ft_check_separator(str[0]) == 1)
		ret++;
	while (str[i] != '\0')
	{
		if (ft_check_separator(str[i]) == 1)
		{
			if (ft_check_separator(str[i - 1]) == 0)
				ret++;
		}
		i++;
	}
	return (ret);
}

char			**ft_split_whitespaces(char *str)
{
	char	**tab;
	int		i;
	int		k;

	i = 0;
	k = 0;
	tab = (char**)malloc(sizeof(char*) * (ft_count_words(str) + 1));
	if (ft_check_separator(str[k]) == 1)
	{
		tab[i] = (char*)malloc(sizeof(char) * (ft_strlenwp(str, &i, 1) + 1));
		tab[i] = ft_strcpy(tab[i], str);
		k += ft_strlenwp(str, &i, 2);
	}
	while (i < ft_count_words(str))
	{
		if (ft_check_separator(str[k]) == 1)
		{
			tab[i] = (char*)malloc(sizeof(char) * (ft_strlenwp(str, &i, 1) + 1));
			tab[i] = ft_strcpy(tab[i], &str[k]);
			k += ft_strlenwp(&str[k], &i, 2);
		}
		k++;
	}
	tab[i] = NULL;
	return (tab);
}
