/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 21:40:29 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/19 14:28:45 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

t_hash	*hash_new(char *key, void *value, size_t size)
{
	t_hash *new;

	if (!key || !(new = ft_memalloc(sizeof(t_hash))))
		return (NULL);
	new->key = ft_strdup(key);
	if (value)
	{
		if (!(new->value = ft_memalloc(size)))
		{
			free(new);
			return (NULL);
		}
		ft_memcpy(new->value, value, size);
		new->size = size;
	}
	else
	{
		new->value = NULL;
		new->size = 0;
	}
	return (value ? new : NULL);
}
