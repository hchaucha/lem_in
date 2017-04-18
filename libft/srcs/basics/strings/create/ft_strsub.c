/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 03:09:00 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/07 15:34:15 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *str;

	if (s == NULL)
		return (NULL);
	str = malloc(sizeof(*str) * len + 1);
	if (str == NULL)
		return (str);
	s += start;
	start = (unsigned int)len;
	while (len-- > 0)
		*str++ = *s++;
	*str = '\0';
	return (str - start);
}
