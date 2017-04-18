/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_modifs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 02:01:14 by hchaucha          #+#    #+#             */
/*   Updated: 2016/09/28 17:01:30 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*applyflag(t_opts *opts, char *str)
{
	if (opts->flags['#'] && opts->type == 'x' && ft_strlen(str))
		return (ft_strtolower(addhexachar(str, 1)));
	if (opts->flags['#'] && opts->type == 'X' && ft_strlen(str))
		return (addhexachar(str, 1));
	if (opts->flags['#'] && (opts->type == 'o' || opts->type == 'O'))
		return (addoctachar(str));
	if (issigned(opts) && opts->flags['+'])
		if (str[0] != '-')
			str = straddnchar(str, 0, 1, '+');
	if (issigned(opts) && ft_isdigit(str[0]) && opts->flags[' '])
		str = straddnchar(str, 0, 1, ' ');
	return (str);
}

int				check_findname(t_opts *opts)
{
	if ((opts->type == 'p' && opts->flags['0']) ||
		(ishexa(opts) && opts->flags['#'] && opts->flags['0']))
		return (1);
	return (0);
}

char			*applywidth(t_opts *opts, char *str)
{
	int		length;
	int		way;
	char	c;

	c = ' ';
	way = 0;
	if (check_findname(opts))
		opts->width = opts->width - 2;
	if (isocta(opts) && opts->flags['#'] && opts->flags['0'])
		opts->width = opts->width - 1;
	if (opts->flags['-'])
		way = 1;
	else if (opts->flags['0'])
		c = '0';
	length = ft_strlen(str);
	if (str[0] == '\0' && opts->type == 'c')
		length = 1;
	if (opts->width > length)
	{
		if (issigned(opts) && opts->flags['0'] && !opts->flags['-'])
			str = straddncharsigned(str, opts->width - length, c);
		else
			str = straddnchar(str, way, opts->width - length, c);
	}
	return (str);
}

wchar_t			*applywidthwchar(t_opts *opts, wchar_t *wstr)
{
	int		length;
	int		way;
	char	c;

	c = ' ';
	way = 0;
	if (opts->flags['-'])
		way = 1;
	else if (opts->flags['0'])
		c = '0';
	length = ft_wstrlen(wstr);
	if (opts->width > length)
	{
		wstr = wstraddnchar(wstr, way, opts->width - length, c);
	}
	return (wstr);
}
