/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 01:48:02 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/07 15:24:09 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putwchar(wchar_t chr)
{
	if (chr <= 0x7F)
		ft_putbuffer(chr, 0);
	else if (chr <= 0x7FF)
	{
		ft_putbuffer((chr >> 6) + 0xC0, 0);
		ft_putbuffer((chr & 0x3F) + 0x80, 0);
	}
	else if (chr <= 0xFFFF)
	{
		ft_putbuffer((chr >> 12) + 0xE0, 0);
		ft_putbuffer(((chr >> 6) & 0x3F) + 0x80, 0);
		ft_putbuffer((chr & 0x3F) + 0x80, 0);
	}
	else if (chr <= 0x10FFFF)
	{
		ft_putbuffer((chr >> 18) + 0xF0, 0);
		ft_putbuffer(((chr >> 12) & 0x3F) + 0x80, 0);
		ft_putbuffer(((chr >> 6) & 0x3F) + 0x80, 0);
		ft_putbuffer((chr & 0x3F) + 0x80, 0);
	}
}

void			ft_putwstr(wchar_t *wstr)
{
	int	i;

	i = 0;
	while (wstr[i])
	{
		ft_putwchar(wstr[i]);
		i++;
	}
}

int				ft_wcharlen(wchar_t c)
{
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF)
	{
		return (2);
	}
	else if (c <= 0xFFFF)
	{
		return (3);
	}
	else if (c <= 0x10FFFF)
	{
		return (4);
	}
	return (-1);
}

int				ft_wstrlen(wchar_t *wstr)
{
	int	i;
	int	nbwrite;

	i = 0;
	nbwrite = 0;
	while (wstr[i])
	{
		nbwrite += ft_wcharlen(wstr[i]);
		i++;
	}
	return (nbwrite);
}
