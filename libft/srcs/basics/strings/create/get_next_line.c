/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 21:34:40 by hchaucha          #+#    #+#             */
/*   Updated: 2017/01/30 16:40:05 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				next_line(char ***stock, char ***line, int i)
{
	char			*tmp;
	char			*sub;

	tmp = ft_strdup(**line);
	free(**line);
	sub = ft_strsub(**stock, 0, i);
	if (!(**line = ft_strjoin(tmp, sub)))
		return (-1);
	free(tmp);
	free(sub);
	tmp = ft_strsub(**stock, i + 1, ft_strlen(**stock));
	free(**stock);
	**stock = ft_strdup(tmp);
	free(tmp);
	return (1);
}

int				end_of_buff(char ***stock, char ***line)
{
	char			*tmp;

	tmp = ft_strdup(**line);
	free(**line);
	if (!(**line = ft_strjoin(tmp, **stock)))
		return (-1);
	free(tmp);
	if (**stock != NULL)
		free(**stock);
	if (!(**stock = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	return (1);
}

int				get_line(int out, int fd, char **stock, char **line)
{
	int			i;

	i = -1;
	while (out != -1 && ++i > -1)
	{
		if ((*stock)[i] == '\n')
		{
			if (next_line(&stock, &line, i) == -1)
				return (-1);
			return (1);
		}
		if (!((*stock)[i]))
		{
			if (end_of_buff(&stock, &line) == -1)
				return (-1);
			out = read(fd, *stock, BUFF_SIZE);
			if (out == 0 && ft_strlen(*line) > 0)
				return (1);
			else if (out == 0)
				return (0);
			i = -1;
		}
	}
	return (out);
}

int				get_next_line(int const fd, char **line)
{
	static char	*stock = NULL;
	int			out;

	if (!line || fd < 0 || fd == 2)
		return (-1);
	*line = ft_strnew(1);
	**line = '\0';
	out = 0;
	if (!stock)
	{
		if (!(stock = ft_strnew(BUFF_SIZE + 1)))
			return (-1);
		if ((out = read(fd, stock, BUFF_SIZE)) == -1)
			return (-1);
	}
	out = get_line(out, fd, &stock, line);
	if (out > 0)
		out = 1;
	return (out);
}
