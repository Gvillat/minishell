/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:44:03 by guvillat          #+#    #+#             */
/*   Updated: 2018/11/09 11:44:08 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_itoa(int n)
{
	int		nbr;
	int		size;
	char	*str;

	if (n == -2147483648 || n == 0)
		return (ft_strdup(!n ? "0" : "-2147483648"));
	nbr = n;
	size = ft_decade(nbr);
	str = ft_strnew(size + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		ft_pushchar(str, '-');
		n = -n;
	}
	nbr = ft_power(10, size - 1);
	while (nbr > 0)
	{
		str = ft_pushchar(str, (n / nbr) + 48);
		n = n % nbr;
		nbr = nbr / 10;
	}
	return (str);
}
