/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 03:02:50 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/07 15:32:06 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dstlen;
	size_t		n;
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	n = size;
	while (*d != '\0' && n-- > 0)
		d++;
	dstlen = d - dst;
	n = size - dstlen;
	if (n == 0)
		return (dstlen + ft_strlen(src));
	while (*s != '\0')
	{
		if (n > 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (dstlen + (s - src));
}
