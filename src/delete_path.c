/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 23:06:27 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/20 15:51:12 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				delete_path_from_tab(char **tab, t_path *path,\
												int size, int end)
{
	int			i;
	int			actual;

	if (path->next->room != end)
	{
		path = path->next;
		actual = path->room;
		while (path && actual != end)
		{
			i = -1;
			while (++i < size)
			{
				tab[actual][i] = 0;
				tab[i][actual] = 0;
			}
			path = path->next;
			actual = path->room;
		}
	}
	else
	{
		tab[path->room][path->next->room] = 0;
		tab[path->next->room][path->room] = 0;
	}
}

void				delete_path(t_path *path)
{
	if (path)
	{
		delete_path(path->next);
		free(path);
	}
}

void				delete_wta(int **wta)
{
	int			i;

	i = -1;
	while (wta[++i])
		free(wta[i]);
	free(wta);
}

void				clean_pathlst(t_pathlst *pathlst)
{
	t_pathlst	*tmp;
	t_pathlst	*prev;

	tmp = pathlst->next;
	prev = pathlst;
	while (tmp && tmp->path)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp)
	{
		free(tmp);
		prev->next = NULL;
	}
}
