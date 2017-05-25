/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_nputchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:12:34 by gvillat           #+#    #+#             */
/*   Updated: 2017/05/22 16:12:37 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fpf_printf.h"

void		fpf_nputchar(char c, ssize_t n, PF *argument)
{
	ssize_t	i;
	char	s[2];

	s[0] = c;
	s[1] = '\0';
	i = 0;
	while (i < n)
	{
		fpf_buff(s, argument);
		i++;
	}
}
