/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:02:49 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/20 15:50:13 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char				**parse_map(t_roomlst **roomlst, int *start,\
									int *end, int *ant_nb)
{
	char			**tab;
	t_inputlst		**inputlst;

	tab = NULL;
	inputlst = malloc(sizeof(t_inputlst *));
	get_ant_nb(inputlst, ant_nb);
	if (get_roomlst(roomlst, start, end, inputlst))
	{
		tab = get_tab(roomlst, inputlst);
	}
	if (!can_be_solved(tab, start, end, ant_nb))
	{
		delete_inputlst(*inputlst);
		free(inputlst);
		ft_printf("ERROR\n");
		exit(1);
	}
	print_inputlst(*inputlst);
	delete_inputlst(*inputlst);
	free(inputlst);
	return (tab);
}
