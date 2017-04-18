/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 03:04:48 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/07 15:32:42 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	unsigned int srclen;
	unsigned int i;

	i = n;
	srclen = ft_strlen(src);
	if (srclen <= n)
	{
		n -= srclen;
		while (srclen-- > 0)
			*dst++ = *src++;
		while (n-- > 0)
			*dst++ = 0;
		return (dst - i);
	}
	return ((char *)ft_memcpy(dst, src, n));
}
