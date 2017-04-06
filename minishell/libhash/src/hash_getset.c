/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_getset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 14:16:11 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/20 14:23:16 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

t_hash	*hash_getset(t_hash **hash, char *key, void *value, size_t size)
{
	t_hash *current;

	if (!hash)
		return (NULL);
	if ((current = hash_get(*hash, key, FALSE)))
		return (current);
	return (hash_set(hash, key, value, size));
}
