/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:52:51 by guvillat          #+#    #+#             */
/*   Updated: 2018/11/09 11:54:35 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*ptr_lst;
	t_list		*ptr_newlst;
	t_list		*new_head;
	t_list		*new;

	ptr_lst = lst;
	if (!lst)
		return (NULL);
	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	new = f(ptr_lst);
	ptr_lst = ptr_lst->next;
	new_head = new;
	ptr_newlst = new;
	while (ptr_lst != NULL)
	{
		if (!(new = malloc(sizeof(t_list))))
			return (NULL);
		new = f(ptr_lst);
		ptr_newlst->next = new;
		ptr_newlst = ptr_newlst->next;
		ptr_lst = ptr_lst->next;
	}
	ptr_newlst->next = NULL;
	return (new_head);
}
