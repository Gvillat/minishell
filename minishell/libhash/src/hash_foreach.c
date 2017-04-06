/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_foreach.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 15:14:05 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/19 15:19:36 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

void	hash_foreach(t_hash *hash
, void (*f)(char *, void *, size_t, void *), void *ptr)
{
	t_hash *current;

	if (!f)
		return ;
	current = hash;
	while (current)
	{
		f(current->key, current->value, current->size, ptr);
		current = current->next;
	}
}
