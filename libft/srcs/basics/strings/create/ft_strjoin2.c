/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 03:02:26 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/07 15:31:56 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	char *tmp;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	tmp = NULL;
	str = NULL;
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	str = ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	tmp = ft_strdup(str);
	free(str);
	return (tmp);
}
