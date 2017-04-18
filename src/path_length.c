/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 23:18:43 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/06 16:52:52 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				path_length(t_path *path)
{
	if (path)
		return (1 + path_length(path->next));
	return (0);
}

int				paths_capacity(t_pathlst *pathlst)
{
	int			paths_nb;

	paths_nb = 1;
	while (pathlst->next)
	{
		paths_nb++;
		pathlst = pathlst->next;
	}
	return (paths_nb + (path_length(pathlst->path) - 2 + \
				(path_length(pathlst->path) == 2)));
}
