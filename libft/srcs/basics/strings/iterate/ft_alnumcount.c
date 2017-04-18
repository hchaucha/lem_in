/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alnumcount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 16:09:00 by hchaucha          #+#    #+#             */
/*   Updated: 2016/06/29 16:09:13 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_alnumcount(char *str)
{
	int		i;

	i = 0;
	while (*str != '\0')
		if (ft_isalnum(*str++))
			i++;
	return (i);
}
