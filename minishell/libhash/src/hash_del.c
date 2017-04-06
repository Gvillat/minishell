/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 23:16:52 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/18 23:19:01 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

void	hash_del(t_hash **hash, void (*f)(void *, size_t))
{
	if (!hash || !(*hash))
		return ;
	if ((*hash)->next)
		hash_del(&((*hash)->next), f);
	hash_delone(hash, f);
}
