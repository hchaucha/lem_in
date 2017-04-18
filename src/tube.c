/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 14:05:16 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/20 15:59:22 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				is_tube_bis(char *str, t_roomlst **roomlst, t_roomlst *start)
{
	int			i;
	t_roomlst	*tmp;

	while (start && !(ft_strcmp(str, start->name) == '-' &&\
				str[ft_strlen(start->name)] == '-'))
		start = start->next;
	if (start && ft_strlen(str) > ft_strlen(start->name) + 1)
	{
		tmp = *roomlst;
		i = ft_strlen(start->name) + 1;
		while (tmp && ft_strcmp(str + i, tmp->name))
			tmp = tmp->next;
		if (tmp == NULL)
			return (is_tube_bis(str, roomlst, start->next));
		return (1);
	}
	return (0);
}

int				is_tube(char *str, t_roomlst **roomlst)
{
	t_roomlst		*tmp;
	char			**split;

	if (ft_stroccu(str, '-') > 1)
		return (is_tube_bis(str, roomlst, *roomlst));
	split = ft_strsplit(str, '-');
	if (!split[0] || !split[1] || split[2])
	{
		ft_delete_map(split);
		return (0);
	}
	tmp = *roomlst;
	while (tmp != NULL && ft_strcmp(tmp->name, split[0]))
		tmp = tmp->next;
	if (tmp == NULL)
	{
		ft_delete_map(split);
		return (0);
	}
	tmp = *roomlst;
	while (tmp != NULL && ft_strcmp(tmp->name, split[1]))
		tmp = tmp->next;
	ft_delete_map(split);
	return (tmp != NULL);
}

char			**get_tab(t_roomlst **roomlst, t_inputlst **inputlst)
{
	int				size;
	char			*str;
	char			**map;

	size = roomlst_size(*roomlst);
	map = create_tube(size);
	str = last_input(inputlst);
	add_tube(map, str, roomlst, *roomlst);
	if (get_next_line(0, &str) == 1)
	{
		while (str && (is_tube(str, roomlst) || *str == '#'))
		{
			add_to_inputlst(inputlst, str);
			if (*str != '#')
				add_tube(map, str, roomlst, *roomlst);
			str = NULL;
			get_next_line(0, &str);
		}
	}
	return (map);
}

char			**create_tube(int size)
{
	int				i;
	char			**map;

	i = -1;
	map = malloc(sizeof(char *) * size + 1);
	map[size] = NULL;
	while (++i < size)
		map[i] = ft_strnew(size);
	return (map);
}

void			add_tube(char **map, char *str, t_roomlst **roomlst,\
								t_roomlst *start)
{
	int			i;
	t_roomlst	*tmp;

	while (start && !(ft_strcmp(str, start->name) == '-' &&\
				str[ft_strlen(start->name)] == '-'))
		start = start->next;
	if (start && ft_strlen(str) > ft_strlen(start->name) + 1)
	{
		tmp = *roomlst;
		i = ft_strlen(start->name) + 1;
		while (tmp && ft_strcmp(str + i, tmp->name))
			tmp = tmp->next;
		if (tmp == NULL)
			return (add_tube(map, str, roomlst, start->next));
		else if (start != tmp)
		{
			map[get_room_index(roomlst, start->name)]\
				[get_room_index(roomlst, tmp->name)] = 1;
			map[get_room_index(roomlst, tmp->name)]\
				[get_room_index(roomlst, start->name)] = 1;
		}
	}
}
