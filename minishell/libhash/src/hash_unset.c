/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:42:04 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/19 18:44:46 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

void	hash_unset(t_hash **hash, char *key, void (*f)(void *, size_t))
{
	t_hash *current;
	t_hash *tmp;

	if (!hash || !(current = *hash))
		return ;
	if (ft_strequ(key, current->key))
	{
		tmp = current->next;
		f(current->value, current->size);
		free(current->key);
		free(current);
		return ((void)(*hash = tmp));
	}
	while (current->next)
	{
		if (ft_strequ(key, current->next->key))
		{
			tmp = current->next->next;
			f(current->next->value, current->next->size);
			free(current->next->key);
			free(current->next);
			return ((void)(current->next = tmp));
		}
		current = current->next;
	}
}
