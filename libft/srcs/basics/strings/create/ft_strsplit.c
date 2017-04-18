/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 03:08:03 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/07 15:34:04 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*ft_skipnotc(const char *s, char c)
{
	while (*s != c && *s != '\0')
		s++;
	return (s);
}

static const char	*ft_skipc(const char *s, char c)
{
	while (*s == c && *s != '\0')
		s++;
	return (s);
}

static int			ft_count_word(char const *s, char c)
{
	if (!s)
		return (0);
	s = ft_skipc(s, c);
	if (*s != '\0')
		return (1 + ft_count_word(ft_skipnotc(s, c), c));
	return (0);
}

static int			ft_count_wlen(char const *s, char c)
{
	if (s && (*s != c && *s != '\0'))
		return (1 + ft_count_wlen(s + 1, c));
	return (0);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**str;
	unsigned int	n;
	unsigned int	wlen;
	unsigned int	nword;

	wlen = 0;
	nword = ft_count_word(s, c);
	str = malloc(sizeof(*str) * nword + 1);
	str[nword] = NULL;
	n = 0;
	while (n != nword)
	{
		s = ft_skipc(s, c);
		wlen = ft_count_wlen(s, c);
		str[n] = ft_strsub(s, 0, wlen);
		s = ft_skipnotc(s, c);
		n++;
	}
	return (str);
}
