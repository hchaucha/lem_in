/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 14:33:20 by hchaucha          #+#    #+#             */
/*   Updated: 2017/01/30 16:38:39 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isnumber(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (i == 0 || (i == 1 && *str == '-'))
		return (0);
	if ((ft_strlen(str + (str[0] == '-')) > 10 || (ft_strlen(str +\
		(str[0] == '-')) == 10 && str[str[0] == '-'] > '2')) ||\
															(str[0] == '-' &&\
		ft_atoi(str) > 0) || (str[0] != '-' && ft_atoi(str) < 0))
		return (0);
	return (1);
}
