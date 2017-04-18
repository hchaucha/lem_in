/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 23:23:46 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/20 15:57:48 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				is_empty(t_path *path)
{
	if (path && path->next)
	{
		if (path->ant_id != 0)
			return (0);
		return (is_empty(path->next));
	}
	return (1);
}

int				are_empty(t_pathlst *pathlst)
{
	if (pathlst)
	{
		if (is_empty(pathlst->path))
			return (are_empty(pathlst->next));
		return (0);
	}
	return (1);
}

t_pathlst		*forward_tmp(t_pathlst *tmp, int min)
{
	if (tmp->next && min)
		tmp = tmp->next;
	while (tmp->next && path_length(tmp->path) == path_length(tmp->next->path))
		tmp = tmp->next;
	return (tmp);
}

void			fill_pathlst(t_pathlst *pathlst, int ant_nb)
{
	t_pathlst	*tmp;
	t_pathlst	*fill;

	tmp = forward_tmp(pathlst, 0);
	while (ant_nb > 0)
	{
		while ((!tmp->next || tmp->ant_to_go + path_length(tmp->path) < \
					path_length(tmp->next->path)) && ant_nb > 0)
		{
			fill = pathlst;
			while (fill != tmp && ant_nb > 0)
			{
				fill->ant_to_go++;
				ant_nb--;
				fill = fill->next;
			}
			if (ant_nb > 0)
			{
				fill->ant_to_go++;
				ant_nb--;
			}
		}
		tmp = forward_tmp(tmp, 1);
	}
}

void			print_solution(t_roomlst *roomlst, t_pathlst *pathlst,\
										int ant_nb)
{
	int			sent;

	sent = 1;
	fill_pathlst(pathlst, ant_nb);
	ft_printf("\n");
	while (sent <= ant_nb || !are_empty(pathlst))
	{
		sent = send_one_in_each(roomlst, pathlst, sent, 1);
		ft_printf("\n");
	}
}
