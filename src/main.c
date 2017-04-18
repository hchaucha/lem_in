/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 02:33:47 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/20 15:55:58 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				main(void)
{
	lem_in();
	return (1);
}

void			lem_in(void)
{
	char			**tab;
	int				*ant_nb;
	int				*start;
	int				*end;
	t_roomlst		**lst;

	start = malloc(sizeof(int));
	end = malloc(sizeof(int));
	ant_nb = malloc(sizeof(int));
	lst = malloc(sizeof(t_roomlst *));
	*lst = NULL;
	*start = -1;
	*end = -1;
	tab = parse_map(lst, start, end, ant_nb);
	print_solution(*lst, find_paths(tab, *start, *end, *ant_nb), *ant_nb);
	ft_delete_map(tab);
	free(start);
	free(end);
	free(ant_nb);
}
