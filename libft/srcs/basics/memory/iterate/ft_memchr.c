/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 02:52:40 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/07 15:29:21 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *ptr;

	if (s == NULL)
		return (NULL);
	ptr = (unsigned char *)s;
	while (n > 0 && *ptr != (unsigned char)c)
	{
		n--;
		ptr++;
	}
	if (n == 0)
		return (NULL);
	return (ptr);
}
