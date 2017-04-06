/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 22:34:33 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/18 22:38:38 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

int		hash_count(t_hash *hash)
{
	int		i;
	t_hash	*current;

	i = 0;
	current = hash;
	while (current)
	{
		++i;
		current = current->next;
	}
	return (i);
}
