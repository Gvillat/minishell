/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:35:05 by guvillat          #+#    #+#             */
/*   Updated: 2018/11/09 11:37:05 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_atoi(const char *nbr)
{
	int result;
	int neg;

	result = 0;
	neg = 0;
	while (*nbr == ' ' || ft_isescaped(*nbr))
		nbr++;
	if (*nbr == '-' || *nbr == '+')
		neg = (*(nbr++) == '-') ? 1 : 0;
	while (*nbr && ft_isdigit(*nbr))
		result = result * 10 + (*(nbr++) - 48);
	return (neg ? result * -1 : result);
}
