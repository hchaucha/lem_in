/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 03:07:41 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/07 15:33:55 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*rev;
	int		i;
	int		n;

	i = 1;
	if (str == NULL)
		return (NULL);
	n = ft_strlen(str);
	rev = (char *)malloc(sizeof(*rev) * n + 1);
	while (*str != '\0')
		rev[n - i++] = *str++;
	rev[n] = '\0';
	return (rev);
}
