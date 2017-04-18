/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 03:09:51 by hchaucha          #+#    #+#             */
/*   Updated: 2016/09/23 03:09:57 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*start;
	char	*end;
	char	*str;
	size_t	n;

	if (s == NULL)
		return (NULL);
	start = (char *)s;
	end = (char *)s;
	while (((*start == ' ' || *start == '\n') || *start == '\t') && \
														*start != '\0')
		start++;
	while (*end != '\0')
		end++;
	end--;
	while (((*end == ' ' || *end == '\n') || *end == '\t') && end > start)
		end--;
	n = (size_t)(end - start);
	str = malloc(sizeof(*str) * n + 1);
	while (start <= end)
		*str++ = *start++;
	*str = '\0';
	return (str - n - 1);
}
