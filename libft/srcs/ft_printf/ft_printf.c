/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 01:43:24 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/07 15:23:31 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			writechar(char c, int *len)
{
	(*len)++;
	ft_putbuffer(c, 0);
}

void			intinit(int *len, int *pos)
{
	*len = 0;
	*pos = 0;
}

int				ft_printf(char *format, ...)
{
	va_list		ap;
	t_opts		*new;
	int			pos;
	int			len;

	intinit(&len, &pos);
	if (!format)
		return (-1);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			new = newopts(format, &pos, &ap);
			len += renderopts(new, &ap);
			format += cleanopts(new);
		}
		else
			writechar(*format, &len);
		incremente(&format, &pos);
	}
	va_end(ap);
	ft_putbuffer(0, 1);
	return (len);
}

void			incremente(char **format, int *pos)
{
	if (**format)
	{
		(*format)++;
		(*pos)++;
	}
}
