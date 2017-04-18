/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hchaucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 10:45:07 by hchaucha          #+#    #+#             */
/*   Updated: 2017/01/30 16:12:11 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_CHARS_H
# define LIBFT_CHARS_H

/*
** Check
*/
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);

/*
** Output
*/
void		ft_putchar(char c);
void		ft_putchar_fd(char c, int fd);

/*
** Transform
*/
int			ft_tolower(int c);
int			ft_toupper(int c);

#endif
