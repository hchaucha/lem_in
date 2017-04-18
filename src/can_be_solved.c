/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_be_solved.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:10:24 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/20 15:51:24 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				can_be_solved(char **tab, int *start, int *end, int *ant_nb)
{
	int				ret;
	char			**new;

	if (!tab || !start || !end || !ant_nb)
	{
		return (0);
	}
	if (!*tab || *start == -1 || *end == -1 || *ant_nb <= 0 || *start == *end)
		return (0);
	new = ft_mapdup(tab);
	ret = has_a_path(new, *start, *end, ft_mapsize(new));
	ft_delete_map(new);
	return (ret);
}

int				has_a_path(char **tab, int start, int end, int size)
{
	int			x;
	int			y;
	int			keep_going;

	keep_going = 1;
	while (keep_going && tab[start][end] != 1)
	{
		keep_going = 0;
		y = -1;
		while (++y < size)
		{
			if (tab[start][y] == 1)
			{
				x = -1;
				while (++x < size)
				{
					if (tab[y][x] == 1 && tab[start][x] == 0)
						keep_going = 1;
					if (tab[y][x] == 1 && tab[start][x] == 0)
						tab[start][x] = 1;
				}
			}
		}
	}
	return (tab[start][end] == 1);
}
