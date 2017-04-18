/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roomlst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:17:22 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/20 15:58:54 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				get_roomlst(t_roomlst **roomlst, int *start, int *end,\
									t_inputlst **inputlst)
{
	char			*str;

	if (get_next_line(0, &str) == 1)
	{
		add_to_inputlst(inputlst, str);
		if (is_room(ft_strsplit(str, ' ')))
		{
			add_to_roomlst(roomlst, ft_strsplit(str, ' '));
			return (get_roomlst(roomlst, start, end, inputlst));
		}
		else if (*str == '#')
		{
			if (ft_strcmp(str, "##start") == 0)
				*start = roomlst_size(*roomlst);
			if (ft_strcmp(str, "##end") == 0)
				*end = roomlst_size(*roomlst);
			return (get_roomlst(roomlst, start, end, inputlst));
		}
		else if (is_tube(str, roomlst))
			return (1);
	}
	return (0);
}

int				roomlst_size(t_roomlst *roomlst)
{
	if (roomlst && roomlst->name)
		return (1 + roomlst_size(roomlst->next));
	return (0);
}

void			add_to_roomlst(t_roomlst **roomlst, char **room)
{
	t_roomlst	*tmp;

	tmp = *roomlst;
	if (*roomlst == NULL)
	{
		*roomlst = malloc(sizeof(t_roomlst));
		tmp = *roomlst;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = malloc(sizeof(t_roomlst));
		tmp = tmp->next;
	}
	tmp->next = NULL;
	tmp->name = ft_strdup(room[0]);
	tmp->x = ft_atoi(room[1]);
	tmp->y = ft_atoi(room[2]);
	ft_delete_map(room);
}

int				is_room(char **room)
{
	if (!room || (!room[0] || !room[1] || !room[2]) || (**room == '#' ||\
		**room == 'L') || !ft_isnumber(room[1]) || !ft_isnumber(room[2])\
		|| room[3])
	{
		ft_delete_map(room);
		return (0);
	}
	ft_delete_map(room);
	return (1);
}

int				get_room_index(t_roomlst **roomlst, char *str)
{
	int			i;
	t_roomlst	*tmp;

	i = 0;
	tmp = *roomlst;
	while (tmp && ft_strcmp(tmp->name, str))
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
