/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 22:08:13 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/19 15:01:37 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

void	*hash_get(t_hash *hash, char *key, BOOL val)
{
	t_hash *current;

	current = hash;
	while (current)
	{
		if (ft_strequ(key, current->key))
			return (val ? current->value : current);
		current = current->next;
	}
	return (NULL);
}
