/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_nb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:07:52 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/20 15:11:23 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				get_ant_nb(t_inputlst **inputlst, int *ant_nb)
{
	char			*str;

	*inputlst = malloc(sizeof(t_inputlst));
	(*inputlst)->next = NULL;
	(*inputlst)->input = NULL;
	if (get_next_line(0, &str))
	{
		while (*str == '#')
		{
			add_to_inputlst(inputlst, str);
			get_next_line(0, &str);
		}
		if (ft_isnumber(str) && ft_atoi(str) > 0)
		{
			add_to_inputlst(inputlst, str);
			*ant_nb = ft_atoi(str);
		}
		else
		{
			ft_printf("ERROR\n");
			exit(1);
		}
	}
}
