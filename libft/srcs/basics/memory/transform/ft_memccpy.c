/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 02:52:16 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/07 15:29:16 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *dst2;
	unsigned char *src2;

	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	while (n > 0 && *src2 != (unsigned char)c)
	{
		n--;
		*dst2++ = *src2++;
	}
	if (n == 0)
		return (NULL);
	else
		*dst2++ = *src2++;
	return ((void *)dst2);
}
