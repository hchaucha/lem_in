/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 02:40:44 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/07 15:30:56 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	d;

	d = (char)c;
	i = 0;
	while (s[i] != d && s[i] != '\0')
		i++;
	if (s[i] == '\0' && d == '\0')
		return (&((char*)s)[i]);
	else if (s[i] == d)
		return (&((char*)s)[i]);
	else
		return (NULL);
}
