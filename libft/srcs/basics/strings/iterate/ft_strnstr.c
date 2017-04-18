/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 03:06:17 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/07 15:33:35 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nstr_is_here(const char *s1, const char *s2, size_t n)
{
	if (*s2 == '\0')
		return (1);
	if (*s1 == *s2 && n > 0)
		return (ft_nstr_is_here(s1 + 1, s2 + 1, n - 1));
	return (0);
}

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	if (ft_nstr_is_here(s1, s2, n))
		return ((char *)s1);
	if (*s1 == '\0' || (size_t)ft_strlen(s2) > n)
		return (NULL);
	return (ft_strnstr(s1 + 1, s2, n - 1));
}
