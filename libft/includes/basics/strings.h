/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hchaucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 10:45:07 by hchaucha          #+#    #+#             */
/*   Updated: 2017/01/30 16:36:07 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRINGS_H
# define LIBFT_STRINGS_H

/*
** Create
*/
char	*ft_strdup(char const *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnew(size_t size);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s);
char	*ft_strunsplit(const char **s, char c);
char	**ft_strsplit(char const *s, char c);

/*
** Delete
*/
void	ft_strdel(char **as);

/*
** Iterate
*/
int		ft_alnumcount(char *str);
int		ft_isnumber(char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strequ(char const *s1, char const *s2);
int		ft_strlen_utf8(signed char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
int		ft_strnoccu(char const *str, char c, size_t n);
int		ft_stroccu(const char *str, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *s1, const char *s2);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t	ft_strlen(const char *s);

/*
** Output
*/
void	ft_putendl(char const *s);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putstr(char const *s);
void	ft_putstr_fd(char const *s, int fd);

/*
** Transform
*/
char	*ft_str_add_char(char *str, char c);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strmerge(char *s1, char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
char	*ft_strncpy(char *dst, const char *src, size_t n);
char	*ft_strrev(char *str);
char	*ft_strtolower(char *str);
void	ft_strclr(char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

#endif
