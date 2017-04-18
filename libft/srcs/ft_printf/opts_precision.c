/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 01:56:13 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/07 15:23:48 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			analyseprecisionwildcard(t_opts *opts, va_list *ap)
{
	opts->precision = 1;
	opts->precisionn = va_arg(*ap, int);
	if (opts->precisionn < 0)
	{
		opts->precisionn = 0;
		opts->precision = 0;
	}
}

void			analyseprecision(t_opts *opts, va_list *ap)
{
	char	*str;
	int		nb;

	nb = 0;
	str = opts->str;
	if ((str = ft_strchr(str, '.')))
	{
		if (ft_strchr(str, '*'))
			analyseprecisionwildcard(opts, ap);
		else if ((nb = ft_atoi(++str)))
		{
			opts->precision = 1;
			opts->precisionn = nb;
		}
		else
			opts->precision = 1;
		if ((issigned(opts) || isunsigned(opts)) && opts->precision)
			opts->flags['0'] = 0;
	}
}
