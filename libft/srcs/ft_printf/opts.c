/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 01:52:15 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/07 15:23:36 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			initopts(t_opts *opts, char *start, int *pos)
{
	opts->formatstart = 0;
	opts->formatend = 0;
	opts->type = 0;
	opts->flags = ft_memalloc('1');
	opts->width = 0;
	opts->precision = 0;
	opts->precisionn = 0;
	opts->modify = 0;
	opts->str = ft_strnew(opts->length + 1);
	opts->str = ft_strncpy(opts->str, start, opts->length + 1);
	opts->formatstart = *pos;
	opts->formatend = *pos + opts->length;
	opts->type = opts->str[opts->length];
}

t_opts			*newopts(char *format, int *pos, va_list *ap)
{
	t_opts	*opts;
	char	*start;

	start = format;
	opts = (t_opts*)malloc(sizeof(t_opts));
	opts->length = 0;
	while (!istype(*format) && !(opts->length && *format == '%'))
	{
		if (isflag(*format) || ft_isdigit(*format) ||
			ismod(*format) || *format == '%' ||
			*format == '.' || *format == '*')
		{
			opts->length++;
			format++;
		}
		else
			break ;
	}
	initopts(opts, start, pos);
	analyseopts(opts, ap);
	opts->next = NULL;
	*pos += opts->length;
	return (opts);
}

int				cleanopts(t_opts *opts)
{
	int	length;

	length = opts->length;
	free(opts->str);
	free(opts->flags);
	free(opts->modify);
	free(opts);
	return (length);
}

int				renderopts(t_opts *opts, va_list *ap)
{
	char	*str;
	wchar_t	*wstr;

	str = NULL;
	wstr = NULL;
	if (issigned(opts))
		str = render_opts_numeric_signed(opts, ap);
	if (isunsigned(opts))
		str = render_opts_numeric_unsigned(opts, ap);
	if (iswchar(opts))
		wstr = render_opts_wchar(opts, ap);
	else if (ischar(opts))
		str = render_opts_char(opts, ap);
	if (isptr(opts))
		str = render_opts_ptr(opts, ap);
	if (!istype(opts->type) && opts->type != '%')
		str = render_opts_error(opts, ap, str);
	if (str)
		return (putoptsstr(opts, str));
	else if (wstr)
		return (putoptswstr(opts, wstr));
	else
		return (putoptsnull(opts));
	return (0);
}
