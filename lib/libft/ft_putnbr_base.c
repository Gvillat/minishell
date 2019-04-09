/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:30:37 by guvillat          #+#    #+#             */
/*   Updated: 2018/11/13 15:42:42 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_check_base(char *base)
{
	int		i;
	int		j;

	i = 0;
	if (!base[0] || !base[1])
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || (base[i] < 33 && base[i] > 126))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void		ft_putnbr_base(int nbr, char *base)
{
	long	nb2;

	nb2 = (long)nbr;
	if (ft_check_base(base))
	{
		if (nb2 < 0)
		{
			ft_putchar('-');
			nb2 = -nb2;
		}
		if (nb2 >= (long)ft_strlen(base))
		{
			ft_putnbr_base(nb2 / ft_strlen(base), base);
			ft_putnbr_base(nb2 % ft_strlen(base), base);
		}
		else
			ft_putchar(base[nb2]);
	}
}
