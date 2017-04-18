/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:19:32 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/06 14:36:40 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				print_inputlst(t_inputlst *inputlst)
{
	if (inputlst && inputlst->input)
	{
		ft_printf("%s\n", inputlst->input);
		print_inputlst(inputlst->next);
	}
}

void				print_roomlst(t_roomlst **roomlst)
{
	t_roomlst	*tmp;

	tmp = *roomlst;
	while (tmp)
	{
		ft_printf("%s\n", tmp->name);
		tmp = tmp->next;
	}
}

void				print_path(t_path *path)
{
	if (path)
	{
		ft_printf("%d ", path->room);
		print_path(path->next);
	}
}

void				print_paths(t_pathlst *pathlst)
{
	int			i;

	i = 0;
	while (pathlst)
	{
		ft_printf("PATH %d : ", i);
		print_path(pathlst->path);
		ft_printf("\n");
		pathlst = pathlst->next;
		i++;
	}
}
