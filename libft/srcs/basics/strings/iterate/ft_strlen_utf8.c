/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_utf8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 16:11:51 by hchaucha          #+#    #+#             */
/*   Updated: 2016/06/29 16:12:03 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen_utf8(signed char *str)
{
	if (*str == '\0')
		return (0);
	if (-64 <= (int)*str && (int)*str <= -33)
		if ((int)str[1] <= -65)
			return (1 + ft_strlen_utf8(str + 2));
	if (-32 <= (int)*str && (int)*str <= -17)
		if ((int)str[1] <= -65 && (int)str[2] <= -65)
			return (1 + ft_strlen_utf8(str + 3));
	if (-16 <= (int)*str && (int)*str <= -9)
		if (((int)str[1] <= -65 && (int)str[2] <= -65) && (int)str[3] <= -65)
			return (1 + ft_strlen_utf8(str + 4));
	return (((int)*str > 0) + ft_strlen_utf8(str + 1));
}
