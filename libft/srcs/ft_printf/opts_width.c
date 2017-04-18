/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 01:53:51 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/07 15:23:53 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			delimitwidth(char *str, int *start, int *end)
{
	int	i;

	i = 0;
	*start = 0;
	*end = 0;
	while (str[i] && str[i] != '.')
	{
		if ((ft_isdigit(str[i]) || str[i] == '*') &&
			*start == 0 && str[i] != '0')
		{
			*start = i;
			*end = i;
		}
		else if (ft_isdigit(str[i]) || str[i] == '*')
			*end = i;
		i++;
	}
}

void			analysewidthwildcard(t_opts *opts, va_list *ap)
{
	opts->width = va_arg(*ap, int);
	if (opts->width < 0)
	{
		opts->flags['-'] = 1;
		opts->width *= -1;
	}
}

void			analysewidth(t_opts *opts, va_list *ap)
{
	char	*str;
	int		startwidth;
	int		endwidth;
	char	*width;
	int		u;

	str = opts->str;
	delimitwidth(str, &startwidth, &endwidth);
	width = (char*)malloc(sizeof(char) * ((endwidth - startwidth + 1) + 1));
	u = 0;
	while (startwidth <= endwidth)
		width[u++] = str[startwidth++];
	width[u] = '\0';
	if (ft_strchr(width, '*'))
	{
		freestr(width);
		analysewidthwildcard(opts, ap);
	}
	else
	{
		opts->width = ft_atoi(width);
		freestr(width);
	}
}
