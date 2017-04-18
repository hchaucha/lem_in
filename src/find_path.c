/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:35:40 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/20 15:58:09 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_pathlst			*find_paths(char **tab, int start, int end, int ant_nb)
{
	t_pathlst	*path_lst;
	t_pathlst	*tmp;

	tmp = malloc(sizeof(t_pathlst));
	tmp->next = NULL;
	tmp->ant_to_go = 0;
	tmp->path = get_path(tab, start, end);
	path_lst = tmp;
	while (tmp->path != NULL && paths_capacity(path_lst) < ant_nb)
	{
		tmp->next = malloc(sizeof(t_pathlst));
		tmp = tmp->next;
		tmp->next = NULL;
		tmp->ant_to_go = 0;
		tmp->path = get_path(tab, start, end);
	}
	if (tmp->path == NULL)
		clean_pathlst(path_lst);
	return (path_lst);
}

t_path				*get_path(char **tab, int start, int end)
{
	int		**wta;
	int		size;
	t_path	*path;

	size = ft_mapsize(tab) * sizeof(int);
	wta = malloc(sizeof(int *) * 4);
	wta[0] = (int *)ft_memset(malloc(size), -1, size);
	wta[1] = (int *)ft_memset(malloc(size), 0, size);
	wta[2] = (int *)ft_memset(malloc(size), -1, size);
	wta[3] = NULL;
	wta[0][start] = 0;
	wta[1][start] = 1;
	algo(tab, start, end, wta);
	path = create_path(end, wta);
	delete_wta(wta);
	if (path->room != start)
	{
		delete_path(path);
		return (NULL);
	}
	size /= sizeof(int);
	delete_path_from_tab(tab, path, size, end);
	return (path);
}

t_path				*create_path(int end, int **wta)
{
	int		actual;
	t_path	*path;
	t_path	*tmp;

	path = malloc(sizeof(t_path));
	path->next = NULL;
	path->room = end;
	actual = wta[2][end];
	while (actual != -1)
	{
		tmp = malloc(sizeof(t_path));
		tmp->ant_id = 0;
		tmp->room = actual;
		tmp->next = path;
		actual = wta[2][actual];
		path = tmp;
	}
	return (path);
}
