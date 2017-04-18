/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 01:59:12 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/07 15:24:16 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*render_opts_char(t_opts *opts, va_list *ap)
{
	char	*str;
	char	c;

	str = NULL;
	if (opts->type == '%')
		str = ft_strdup("%");
	else if (opts->type == 'c')
	{
		c = va_arg(*ap, int);
		str = ft_strdup(" ");
		str[0] = c;
		str = applyprecision(opts, str);
	}
	else
	{
		str = va_arg(*ap, char *);
		if (!str)
			str = ft_strdup("(null)");
		else if (!str)
			str = ft_strdup("");
		else
			str = ft_strdup(str);
		str = applyprecision(opts, str);
	}
	return (applywidth(opts, str));
}

char			*render_opts_error(t_opts *opts, va_list *ap, char *str)
{
	char	*s;

	(void)ap;
	(void)str;
	s = ft_strdup(" ");
	s[0] = opts->str[ft_strlen(opts->str) - 1];
	s = applywidth(opts, s);
	return (s);
}

wchar_t			*render_opts_wchar(t_opts *opts, va_list *ap)
{
	wchar_t	*wstr;

	if (opts->type == 'C' ||
		(opts->type == 'c' && !ft_strcmp(opts->modify, "l")))
	{
		wstr = (wchar_t*)malloc(sizeof(wchar_t) * 2);
		wstr[0] = va_arg(*ap, int);
		wstr[1] = '\0';
	}
	else
	{
		wstr = va_arg(*ap, wchar_t *);
		if (wstr)
			wstr = ft_wcsdup(wstr);
		if (!wstr)
			wstr = ft_wcsdup(L"(null)");
		wstr = applyprecisionwchar(opts, wstr);
	}
	wstr = applywidthwchar(opts, wstr);
	return (wstr);
}

char			*render_opts_ptr(t_opts *opts, va_list *ap)
{
	char		*str;
	uintmax_t	ptr;

	ptr = va_arg(*ap, uintmax_t);
	str = ft_uitoa_base(ptr, 16);
	if (opts->flags['0'])
	{
		str = applyprecision(opts, str);
		str = applywidth(opts, str);
		str = ft_strtolower(addhexachar(str, 0));
	}
	else
	{
		str = applyprecision(opts, str);
		str = ft_strtolower(addhexachar(str, 0));
		str = applywidth(opts, str);
	}
	return (str);
}
