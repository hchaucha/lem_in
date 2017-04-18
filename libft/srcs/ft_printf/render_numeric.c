/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_numeric.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 01:59:33 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/07 15:24:22 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t		render_opts_numeric_unsigned_get(t_opts *opts, va_list *ap)
{
	uintmax_t		n;

	if (!ft_strcmp(opts->modify, "l") || opts->type == 'O' || opts->type == 'U')
		n = (unsigned long)va_arg(*ap, uintmax_t);
	else if (!ft_strcmp(opts->modify, "hh"))
		n = (unsigned char)(va_arg(*ap, uintmax_t));
	else if (!ft_strcmp(opts->modify, "h"))
		n = (unsigned short)va_arg(*ap, uintmax_t);
	else if (!ft_strcmp(opts->modify, "ll"))
		n = (unsigned long long)va_arg(*ap, uintmax_t);
	else if (!ft_strcmp(opts->modify, "z"))
		n = (size_t)(va_arg(*ap, uintmax_t));
	else if (!ft_strcmp(opts->modify, "j"))
		n = (uintmax_t)(va_arg(*ap, uintmax_t));
	else
		n = (unsigned int)(va_arg(*ap, uintmax_t));
	return (n);
}

char			*render_opts_numeric_uitoa(t_opts *opts, uintmax_t n)
{
	char	*str;

	if (opts->type == 'o')
		str = ft_uitoa_base(n, 8);
	else if (opts->type == 'O')
		str = ft_uitoa_base(n, 8);
	else if (opts->type == 'x')
		str = ft_strtolower(ft_uitoa_base(n, 16));
	else if (opts->type == 'X')
		str = ft_uitoa_base(n, 16);
	else if (opts->type == 'u')
		str = ft_uitoa_base(n, 10);
	else if (opts->type == 'b')
		str = ft_uitoa_base(n, 2);
	else
		str = ft_uitoa_base(n, 10);
	return (str);
}

int				ishexaocta(t_opts *opts)
{
	if ((ishexa(opts) && opts->flags['#'] && !opts->flags['0']) ||
			(isocta(opts) && opts->flags['#'] && !opts->flags['0']))
		return (1);
	return (0);
}

char			*render_opts_numeric_unsigned(t_opts *opts, va_list *ap)
{
	uintmax_t	n;
	char		*str;

	n = render_opts_numeric_unsigned_get(opts, ap);
	str = render_opts_numeric_uitoa(opts, n);
	if (isocta(opts) && opts->precision && opts->precisionn)
	{
		str = applyflag(opts, str);
		str = applyprecision(opts, str);
		str = applywidth(opts, str);
	}
	else if (ishexaocta(opts))
	{
		str = applyprecision(opts, str);
		str = applyflag(opts, str);
		str = applywidth(opts, str);
	}
	else
	{
		str = applyprecision(opts, str);
		str = applywidth(opts, str);
		str = applyflag(opts, str);
	}
	return (str);
}

char			*render_opts_numeric_signed(t_opts *opts, va_list *ap)
{
	intmax_t		n;
	char			*str;

	if (!ft_strcmp(opts->modify, "l") || opts->type == 'D')
		n = (long)va_arg(*ap, intmax_t);
	else if (!ft_strcmp(opts->modify, "hh"))
		n = (char)(va_arg(*ap, intmax_t));
	else if (!ft_strcmp(opts->modify, "h"))
		n = (short)va_arg(*ap, intmax_t);
	else if (!ft_strcmp(opts->modify, "ll"))
		n = (long long)va_arg(*ap, intmax_t);
	else if (!ft_strcmp(opts->modify, "z"))
		n = (size_t)(va_arg(*ap, intmax_t));
	else if (!ft_strcmp(opts->modify, "j"))
		n = (intmax_t)(va_arg(*ap, intmax_t));
	else
		n = (int)(va_arg(*ap, intmax_t));
	str = ft_itoa_base(n, 10);
	str = applyprecision(opts, str);
	str = applyflag(opts, str);
	str = applywidth(opts, str);
	return (str);
}
