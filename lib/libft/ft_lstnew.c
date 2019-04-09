/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:54:43 by guvillat          #+#    #+#             */
/*   Updated: 2018/11/09 11:56:21 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *ret;

	if (!(ret = ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		ret->content = NULL;
		ret->content_size = 0;
		return (ret);
	}
	ret->content_size = content_size;
	if (!(ret->content = ft_memalloc(content_size)))
		ret->content = NULL;
	else
		ret->content = ft_memcpy(ret->content, content, content_size);
	return (ret);
}
