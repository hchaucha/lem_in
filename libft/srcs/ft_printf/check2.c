/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 01:50:45 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/07 15:23:19 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				issigned(t_opts *opts)
{
	if (opts->type == 'd' || opts->type == 'i' || opts->type == 'D')
		return (1);
	return (0);
}

int				isunsigned(t_opts *opts)
{
	if (opts->type == 'o' || opts->type == 'O' ||
		opts->type == 'x' || opts->type == 'X' ||
		opts->type == 'u' || opts->type == 'U' ||
		opts->type == 'b')
		return (1);
	return (0);
}

int				iswchar(t_opts *opts)
{
	if (opts->type == 'C' ||
		opts->type == 'S' ||
		((!ft_strcmp(opts->modify, "l")) &&
		(opts->type == 'c' || opts->type == 's')))
		return (1);
	return (0);
}

int				ischar(t_opts *opts)
{
	if (opts->type == '%' || opts->type == 'c' || opts->type == 's')
		return (1);
	return (0);
}

int				isptr(t_opts *opts)
{
	if (opts->type == 'p')
		return (1);
	return (0);
}
