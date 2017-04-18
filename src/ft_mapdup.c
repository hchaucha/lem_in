/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 20:55:38 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/20 15:51:47 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char				**ft_mapdup(char **old)
{
	int				i;
	int				n;
	char			**new;

	if (!old)
		return (NULL);
	i = 0;
	n = -1;
	while (old[i])
		i++;
	new = malloc(sizeof(char *) * i + 1);
	while (++n < i)
		new[n] = malloc(sizeof(char) * i);
	new[i] = NULL;
	n = -1;
	while (++n < i * i)
		new[n / i][n % i] = old[n / i][n % i];
	return (new);
}
