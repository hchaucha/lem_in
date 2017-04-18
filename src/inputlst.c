/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputlst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:12:33 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/06 15:00:21 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				add_to_inputlst(t_inputlst **inputlst, char *str)
{
	t_inputlst	*tmp;

	tmp = *inputlst;
	while (tmp->input != NULL && tmp->next != NULL)
		tmp = tmp->next;
	if (tmp->input != NULL)
	{
		tmp->next = malloc(sizeof(inputlst));
		tmp = tmp->next;
	}
	tmp->input = str;
	tmp->next = NULL;
}

char				*last_input(t_inputlst **inputlst)
{
	t_inputlst	*tmp;

	tmp = *inputlst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp->input);
}

void				delete_inputlst(t_inputlst *inputlst)
{
	if (inputlst)
	{
		if (inputlst->next)
			delete_inputlst(inputlst->next);
		if (inputlst->input)
			free(inputlst->input);
		free(inputlst);
	}
}
