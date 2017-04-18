/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strunsplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:36:48 by hchaucha          #+#    #+#             */
/*   Updated: 2017/01/30 16:36:52 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strunsplit(const char **s, char c)
{
	int		i;
	int		len;
	char	*ret;

	i = -1;
	len = 0;
	while (s[++i])
		len += ft_strlen(s[i]);
	ret = ft_strnew(len + i);
	i = -1;
	while (s[++i])
	{
		ret = ft_strncat(ret, s[i], ft_strlen(s[i]));
		ret = straddnchar(ret, 1, 1, c);
	}
	return (ret);
}
