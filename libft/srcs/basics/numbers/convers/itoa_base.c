/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 16:07:39 by hchaucha          #+#    #+#             */
/*   Updated: 2016/06/30 00:34:18 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digitnbr_base(long long int n, int base)
{
	int digits;

	digits = 0;
	if (n < 0)
		digits += 1;
	while (n != 0)
	{
		digits += 1;
		n /= base;
	}
	return (digits);
}

static int	ft_digitnbr_base_unsigned(unsigned long long int n, int base)
{
	int digits;

	digits = 0;
	while (n != 0)
	{
		digits += 1;
		n /= base;
	}
	return (digits);
}

char		*ft_itoa_base_nozero(long long int n, int base)
{
	size_t	size;
	char	*str;
	int		conv;

	conv = 0;
	size = ft_digitnbr_base(n, base);
	str = malloc(sizeof(*str) * size + 1);
	*(str + size) = '\0';
	str += size;
	if (n < 0)
	{
		conv = -2;
		*(str - size) = '-';
	}
	while (n != 0)
	{
		*--str = (char)(n % base) + '0' + (conv * (n % base));
		if (*(str) > '9')
			*(str) += 7;
		n /= base;
	}
	return (str - (conv / -2));
}

char		*ft_itoa_base_unsigned(unsigned long long int n, int base)
{
	size_t	size;
	char	*str;

	size = ft_digitnbr_base_unsigned(n, base);
	str = malloc(sizeof(*str) * size + 1);
	*(str + size) = '\0';
	str += size;
	while (n != 0)
	{
		*--str = (char)(n % base) + '0';
		if (*(str) > '9')
			*(str) += 7;
		n /= base;
	}
	return (str);
}

char		*ft_itoa_base_unsigned_min(unsigned long long int n, int base)
{
	size_t	size;
	char	*str;

	size = ft_digitnbr_base_unsigned(n, base);
	str = malloc(sizeof(*str) * size + 1);
	*(str + size) = '\0';
	str += size;
	while (n != 0)
	{
		*--str = (char)(n % base) + '0';
		if (*str > '9')
			*str += 39;
		n /= base;
	}
	return (str);
}
