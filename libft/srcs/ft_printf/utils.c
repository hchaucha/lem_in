/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 02:03:44 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/07 15:24:30 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			freestr(char *str)
{
	if (*str)
		free(str);
	str = NULL;
}

void			freewstr(wchar_t *wstr)
{
	if (*wstr && ft_wstrlen(wstr) > 0)
		free(wstr);
	wstr = NULL;
}
