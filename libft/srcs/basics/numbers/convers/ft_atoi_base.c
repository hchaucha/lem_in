/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 04:47:26 by hchaucha          #+#    #+#             */
/*   Updated: 2016/07/01 04:47:38 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_base(char *str, int base)
{
	int	final;
	int	tmp;
	int	pow;
	int	n;
	int	signe;

	n = ft_strlen(str) - (*str == '-');
	signe = (*str == '-') ? -1 : 1;
	str += *str == '-';
	pow = 1;
	final = 0;
	while (n-- > 0)
	{
		tmp = 0;
		if (ft_isdigit(str[n]))
			tmp = str[n] - '0';
		else if (ft_isalpha(str[n]) && str[n] <= 'Z')
			tmp = str[n] - ('A' - 10);
		else if (ft_isalpha(str[n]) && str[n] >= 'a')
			tmp = str[n] - ('a' - 10);
		final += tmp * pow;
		pow *= base;
	}
	return (final * signe);
}
