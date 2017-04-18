/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnoccu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 03:05:49 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/07 15:33:29 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnoccu(char const *str, char c, size_t n)
{
	int	i;
	int nbr;

	i = -1;
	nbr = 0;
	if (str == NULL || c == '\0')
		return (0);
	while (str[++i] != '\0' && n > 0)
	{
		if (str[i] == c)
			nbr++;
		n--;
	}
	return (nbr);
}
