/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_one_in_each.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 00:29:58 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/20 15:58:33 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char			*get_room_name(t_roomlst *roomlst, int room)
{
	int			i;

	i = 0;
	while (i++ < room)
		roomlst = roomlst->next;
	return (roomlst->name);
}

void			print_move(t_path *path, t_roomlst *roomlst, int first)
{
	if (first == 0)
		ft_putchar(' ');
	ft_printf("L%d-%s", path->ant_id, get_room_name(roomlst, path->room));
}

int				push_path(t_path *path, t_roomlst *roomlst, int first)
{
	if (path && path->next)
	{
		first = push_path(path->next, roomlst, first);
		if (path->ant_id)
		{
			path->next->ant_id = path->ant_id;
			path->ant_id = 0;
			print_move(path->next, roomlst, first);
			if (first)
				first = 0;
		}
	}
	return (first);
}

int				send_another(t_roomlst *roomlst, t_path *path,\
									int sent, int first)
{
	path->next->ant_id = sent;
	print_move(path->next, roomlst, first);
	return (0);
}

int				send_one_in_each(t_roomlst *roomlst, t_pathlst *pathlst,\
											int sent, int first)
{
	if (pathlst && (pathlst->ant_to_go > 0 || !is_empty(pathlst->path)))
	{
		first = push_path(pathlst->path, roomlst, first);
		if (pathlst->ant_to_go > 0)
		{
			first = send_another(roomlst, pathlst->path, sent, first);
			sent++;
			pathlst->ant_to_go--;
		}
		return (send_one_in_each(roomlst, pathlst->next, sent, first));
	}
	return (sent);
}
