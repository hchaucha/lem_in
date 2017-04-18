/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 02:43:36 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/07 15:32:32 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	j;
	size_t	len;

	j = 0;
	len = ft_strlen(s1);
	while (n > j && s2[j] != '\0')
	{
		s1[len] = s2[j];
		len++;
		j++;
	}
	s1[len] = '\0';
	return (s1);
}
