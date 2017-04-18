/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 03:07:18 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/07 15:33:49 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		*s2;
	size_t		n;

	n = ft_strlen(s);
	s2 = (char *)s + n;
	while (*s2 != (char)c && n-- > 0)
		s2--;
	if (*s2 != (char)c)
		return (NULL);
	return (s2);
}
