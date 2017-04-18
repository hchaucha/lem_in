/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_add_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 14:13:05 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/25 14:13:14 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_add_char(char *str, char c)
{
	char	*to_add;

	to_add = ft_strnew(2);
	*to_add = c;
	return (ft_strmerge(str, to_add));
}

char	*ft_char_add_str(char *str, char c)
{
	char	*to_add;

	to_add = ft_strnew(2);
	*to_add = c;
	return (ft_strmerge(to_add, str));
}

char	*ft_zero_add_str(char *str)
{
	if (*str == '-')
	{
		*str = '0';
		return (ft_char_add_str(str, '-'));
	}
	else
		return (ft_char_add_str(str, '0'));
}
