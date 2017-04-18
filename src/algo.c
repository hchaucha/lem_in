/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 20:36:30 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/20 15:55:27 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			algo(char **tab, int dad, int end, int **wta)
{
	int			son;
	int			size;

	son = -1;
	size = ft_mapsize(tab);
	if (dad != end && dad >= 0)
	{
		while (++son < size)
		{
			if (tab[dad][son] && !wta[1][son] && \
				(wta[0][dad] + 1 < wta[0][son] || wta[0][son] == -1))
			{
				wta[0][son] = wta[0][dad] + 1;
				wta[2][son] = dad;
			}
		}
		wta[1][dad] = 1;
		algo(tab, new_dad(wta, son), end, wta);
	}
}

int				new_dad(int **wta, int size)
{
	int			dad;
	int			n;

	n = -1;
	dad = -1;
	while (++n < size)
		if (wta[0][n] != -1 && !wta[1][n] && (dad == -1 ||\
			wta[0][n] < wta[0][dad]))
			dad = n;
	return (dad);
}
