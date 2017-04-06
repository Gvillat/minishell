/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 23:19:19 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/01/22 14:16:00 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

typedef struct	s_fdslot
{
	int				fd;
	char			*buffer;
	char			*head;
	struct s_fdslot *next;
}				t_fdslot;
int				get_next_line(int const fd, char **line);
#endif
