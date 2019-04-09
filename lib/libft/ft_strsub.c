/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:14:39 by guvillat          #+#    #+#             */
/*   Updated: 2019/01/23 15:14:40 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/ft_printf.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = ft_strnew(len);
	if (s2 == NULL || s == NULL)
		return (NULL);
	while (len--)
	{
		s2[i] = s[start];
		i++;
		start++;
	}
	return (s2);
}

char		*ft_wstrsub(wchar_t *ws, unsigned int start, size_t len)
{
	int		real_len;
	int		i;
	char	*fresh;

	real_len = 0;
	i = 0;
	while (ws[i] != '\0' && (int)len >= ft_wcharlen(ws[i]))
	{
		len -= ft_wcharlen(ws[i]);
		real_len += ft_wcharlen(ws[i]);
		i++;
	}
	fresh = ft_transform_wchar_in_char(ws);
	return (ft_strsub_with_free(fresh, start, real_len));
}

char		*ft_strsub_with_free(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	char	*tmp;
	int		i;

	tmp = NULL;
	if (!s)
		return (NULL);
	tmp = (char*)s;
	if (!(fresh = malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	if (!fresh)
		return (NULL);
	fresh[len] = '\0';
	while (len > 0)
	{
		fresh[i] = s[start];
		i++;
		start++;
		len--;
	}
	free(tmp);
	return (fresh);
}
