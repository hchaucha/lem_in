/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 15:33:08 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/07 15:33:15 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*ptr;

	ptr = (char*)malloc(sizeof(char) * ++size);
	if (!ptr)
		return (NULL);
	else
		ft_bzero(ptr, size);
	return (ptr);
}
