/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 19:06:28 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/07 15:37:56 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include "libft.h"

# define PRINTFBUFFER 400

typedef struct		s_opts
{
	char			*str;
	int				length;
	int				formatstart;
	int				formatend;
	char			type;
	char			*flags;
	int				width;
	int				precision;
	int				precisionn;
	char			*modify;

	struct s_opts	*next;
}					t_opts;

/*
** add_char.c
*/

char				*straddnchar(char *str, int way, int n, char c);
char				*straddncharsigned(char *str, int n, char c);
char				*addhexachar(char *str, int ishexa);
char				*addoctachar(char *str);
wchar_t				*wstraddnchar(wchar_t *wstr, int way, int n, char c);

/*
** apply_modifs.c
*/

char				*applyflag(t_opts *opts, char *str);
char				*applywidth(t_opts *opts, char *str);
int					check_findname(t_opts *opts);
wchar_t				*applywidthwchar(t_opts *opts, wchar_t *str);

/*
** apply_precision.c
*/

wchar_t				*applyprecisionwchar(t_opts *opts, wchar_t *str);
char				*applyprecision(t_opts *opts, char *str);
char				*applyspecialprecision(t_opts *opts, char *str);

/*
** buffer.c
*/

void				ft_putstrn(char *buffer, int len);
void				ft_putstrbuf(char *str);
void				cleanbuffer(char **buffer, int *len, int *wchar);
void				ft_putbuffer(char c, int flush);

/*
** check.c
*/

int					istype(char c);
int					isflag(char c);
int					ismod(char c);
int					isocta(t_opts *opts);
int					ishexa(t_opts *opts);

/*
** check2.c
*/

int					issigned(t_opts *opts);
int					isunsigned(t_opts *opts);
int					iswchar(t_opts *opts);
int					ischar(t_opts *opts);
int					isptr(t_opts *opts);

/*
** ft_itoa_base.c
*/

char				*ft_itoa_base(intmax_t value, int base);
char				*ft_uitoa_base(uintmax_t value, int base);

/*
** ft_printf.c
*/

int					ft_printf(char *format, ...);
void				incremente(char **format, int *pos);
void				intinit(int *len, int *pos);
void				writechar(char c, int *len);

/*
** opts.c
*/

t_opts				*newopts(char *format, int *pos, va_list *ap);
void				initopts(t_opts *opts, char *start, int *pos);
int					renderopts(t_opts *opts, va_list *ap);
int					cleanopts(t_opts *opts);

/*
** opts_analyse.c
*/

void				analyseopts(t_opts *opts, va_list *ap);
void				analyseflags(t_opts *opts);
void				analysemod(t_opts *opts);

/*
** opts_precision.c
*/

void				analyseprecision(t_opts *opts, va_list *ap);
void				analyseprecisionwildcard(t_opts *opts, va_list *ap);

/*
** opts_width.c
*/

void				delimitwidth(char *str, int *start, int *end);
void				analysewidthwildcard(t_opts *opts, va_list *ap);
void				analysewidth(t_opts *opts, va_list *ap);

/*
** print.c
*/

int					putoptsstr(t_opts *opts, char *str);
int					putoptswstr(t_opts *opts, wchar_t *wstr);
int					putoptsnull(t_opts *opts);

/*
** print_wchar.c
*/

void				ft_putwchar(wchar_t chr);
void				ft_putwstr(wchar_t *wstr);
int					ft_wcharlen(wchar_t c);
int					ft_wstrlen(wchar_t *wstr);

/*
** render.c
*/

char				*render_opts_char(t_opts *opts, va_list *ap);
char				*render_opts_ptr(t_opts *opts, va_list *ap);
char				*render_opts_error(t_opts *opts, va_list *ap, char *str);
wchar_t				*render_opts_wchar(t_opts *opts, va_list *ap);

/*
** render_numeric.c
*/

int					ishexaocta(t_opts *opts);
char				*render_opts_numeric_signed(t_opts *opts, va_list *ap);
char				*render_opts_numeric_unsigned(t_opts *opts, va_list *ap);
char				*render_opts_numeric_uitoa(t_opts *opts, uintmax_t n);

/*
** utils.c
*/

void				freestr(char *str);
void				freewstr(wchar_t *wstr);

/*
** wchar.c
*/

int					ft_wcslen(wchar_t *wstr);
wchar_t				*ft_wcsnew(int n);
wchar_t				*ft_wcscpy(wchar_t *dest, wchar_t *src);
wchar_t				*ft_wcsdup(wchar_t *src);
wchar_t				*ft_wcscat(wchar_t *dest, const wchar_t *src);

#endif
