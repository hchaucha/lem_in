/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts_analyse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 01:52:42 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/07 15:23:43 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	analysemod(t_opts *opts)
{
	const char	flags[6][4] = {"hh", "h", "ll", "l", "j", "z"};
	int			i;

	i = 0;
	(void)opts;
	while (flags[i] && i < 6 && !opts->modify)
	{
		if (ft_strstr(opts->str, flags[i]))
		{
			opts->modify = ft_strdup((char *)flags[i]);
			return ;
		}
		i++;
	}
	opts->modify = ft_strdup("");
}

void	analyseflags(t_opts *opts)
{
	char *str;

	str = opts->str;
	while ((*str && (!ft_isdigit(*str) || *str == '0')) && *str != '.')
	{
		if (isflag(*str))
		{
			if (!(opts->flags['+'] && *str == ' ') &&
				!(opts->flags['-'] && *str == '0'))
			{
				opts->flags[(int)*str] = 1;
			}
		}
		str++;
	}
}

void	analyseopts(t_opts *opts, va_list *ap)
{
	analyseflags(opts);
	analysewidth(opts, ap);
	analyseprecision(opts, ap);
	analysemod(opts);
}
