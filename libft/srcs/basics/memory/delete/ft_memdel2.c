/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 12:19:55 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/27 12:21:33 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_memdel2(void ***ap)
{
	int	i;

	if (ap != NULL && *ap != NULL)
	{
		i = -1;
		while ((*ap)[++i])
			ft_memdel((void **)&(*ap)[i]);
		free(*ap);
		*ap = NULL;
	}
}
