/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 15:22:57 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/07 15:23:04 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putstrn(char *buffer, int len)
{
	write(1, buffer, len);
}

void			ft_putstrbuf(char *str)
{
	while (*str)
	{
		ft_putbuffer(*str, 0);
		str++;
	}
}

void			cleanbuffer(char **buffer, int *len, int *wchar)
{
	ft_putstrn(*buffer, *len);
	if (*buffer)
	{
		freestr(*buffer);
		*buffer = NULL;
	}
	*len = 0;
	*wchar = 0;
}

void			ft_putbuffer(char c, int flush)
{
	static char	*buffer;
	static int	wchar;
	static int	len;

	if (flush || len > PRINTFBUFFER)
		cleanbuffer(&buffer, &len, &wchar);
	if (!flush)
	{
		if (!len)
			len = 0;
		if (!wchar)
			wchar = 0;
		if (!buffer)
			buffer = ft_memalloc(PRINTFBUFFER + 1);
		buffer[wchar] = c;
		wchar++;
		len++;
	}
}
