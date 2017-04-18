/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 02:48:11 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/07 15:28:17 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digitnbr(int n)
{
	int digits;

	digits = 0;
	if (n < 0)
		digits += 1;
	while (n != 0)
	{
		digits += 1;
		n /= 10;
	}
	if (digits == 0)
		digits = 1;
	return (digits);
}

char		*ft_itoa(int n)
{
	size_t	size;
	char	*str;
	int		i;
	int		conv;

	conv = 0;
	size = ft_digitnbr(n);
	str = malloc(sizeof(*str) * size + 1);
	*(str + size) = '\0';
	i = 1;
	if (n < 0)
	{
		conv = -2;
		*str = '-';
	}
	if (n == 0)
		*str = '0';
	while (n != 0)
	{
		str[size - i] = (char)(n % 10) + 48 + (conv * (n % 10));
		i++;
		n /= 10;
	}
	return (str);
}
