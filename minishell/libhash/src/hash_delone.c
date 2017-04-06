/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_delone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 22:43:15 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/18 23:21:19 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

void	hash_delone(t_hash **hash, void (*f)(void *, size_t))
{
	if (!hash || !*hash)
		return ;
	if (f)
		f((*hash)->value, (*hash)->size);
	free((*hash)->key);
	ft_memdel((void **)hash);
}
