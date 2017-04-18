/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 16:06:46 by hchaucha          #+#    #+#             */
/*   Updated: 2017/01/30 17:57:50 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmerge(char *s1, char *s2)
{
	int		i;
	int		n;
	char	*final;

	i = 0;
	n = 0;
	final = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s1)
		while (s1[n] != '\0')
			final[i++] = s1[n++];
	n = 0;
	if (s2)
		while (s2[n] != '\0')
			final[i++] = s2[n++];
	free(s1);
	free(s2);
	return (final);
}
