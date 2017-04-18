/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 15:21:49 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/07 15:22:04 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*straddnchar(char *str, int way, int n, char c)
{
	int			i;
	int			length;
	char		*new;

	length = ft_strlen(str);
	new = ft_strnew(length + n);
	i = 0;
	if (way)
	{
		new = ft_strcpy(new, str);
		while (i < n)
			new[length + i++] = c;
	}
	else
	{
		while (i < n)
			new[i++] = c;
		new = ft_strcat(new, str);
	}
	freestr(str);
	return (new);
}

char			*straddncharsigned(char *str, int n, char c)
{
	int			i;
	int			length;
	char		*new;
	int			sign;

	length = ft_strlen(str);
	new = ft_strnew(length + n);
	if (str[0] == '-' || str[0] == '+' || str[0] == ' ')
		sign = 1;
	else
		sign = 0;
	if (sign)
		new = ft_strncat(new, str, 1);
	i = sign;
	while (i < n + sign)
	{
		new[i] = c;
		i++;
	}
	new = ft_strcat(new, &str[sign]);
	freestr(str);
	return (new);
}

char			*addhexachar(char *str, int ishexa)
{
	int				length;
	char			*new;

	length = ft_strlen(str);
	if (!(length == 1 && str[0] == '0' && ishexa))
	{
		new = ft_strnew(length + 2);
		new = ft_strcat(new, "0X");
		new = ft_strcat(new, str);
		freestr(str);
	}
	else
		new = str;
	return (new);
}

char			*addoctachar(char *str)
{
	int			length;
	char		*new;

	length = ft_strlen(str);
	if (!(length == 1 && str[0] == '0'))
	{
		new = ft_strnew(length + 1);
		new = ft_strcat(new, "0");
		new = ft_strcat(new, str);
		freestr(str);
	}
	else
		new = str;
	return (new);
}

wchar_t			*wstraddnchar(wchar_t *wstr, int way, int n, char c)
{
	int				i;
	int				length;
	wchar_t			*new;

	length = ft_wcslen(wstr);
	new = ft_wcsnew(length + n);
	i = 0;
	if (way)
	{
		new = ft_wcscpy(new, wstr);
		while (i < n)
			new[length + i++] = (wchar_t)c;
	}
	else
	{
		while (i < n)
		{
			new[i] = c;
			i++;
		}
		new = ft_wcscat(new, wstr);
	}
	freewstr(wstr);
	return (new);
}
