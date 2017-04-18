/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 03:05:23 by hchaucha          #+#    #+#             */
/*   Updated: 2016/09/23 03:05:28 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	if ((*s1 == '\0' && *s2 == '\0') || n == 0)
		return (1);
	if (*s1 == *s2)
		return (ft_strnequ(s1 + 1, s2 + 1, n - 1));
	return (0);
}
