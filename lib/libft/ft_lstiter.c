/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:52:07 by guvillat          #+#    #+#             */
/*   Updated: 2018/11/09 11:52:32 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (lst->next)
		ft_lstiter(lst->next, f);
	(*f)(lst);
}
