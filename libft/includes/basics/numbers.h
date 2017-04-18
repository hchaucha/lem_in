/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hchaucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 10:45:07 by hchaucha          #+#    #+#             */
/*   Updated: 2017/01/30 16:13:01 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_NUMBERS_H
# define LIBFT_NUMBERS_H

/*
** Convers
*/
int			ft_atoi(const char *str);
int			ft_atoi_base(char *str, int base);
char		*ft_itoa(int n);
char		*ft_itoa_base(intmax_t value, int base);
char		*ft_itoa_base_unsigned(unsigned long long int n, int base);

/*
** Output
*/
void		ft_putnbr(int n);
void		ft_putnbr_fd(int n, int fd);

#endif
