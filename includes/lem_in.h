/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 02:46:42 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/20 16:00:20 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct	s_roomlst
{
	char							*name;
	int								x;
	int								y;
	struct s_roomlst				*next;
}				t_roomlst;

typedef struct	s_path
{
	int						ant_id;
	int						room;
	struct s_path			*next;
}				t_path;

typedef struct	s_pathlst
{
	int						ant_to_go;
	t_path					*path;
	struct s_pathlst		*next;
}				t_pathlst;

typedef struct	s_inputlst
{
	char						*input;
	struct s_inputlst			*next;
}				t_inputlst;

/*
** algo.c
*/

void			algo(char **tab, int dad, int end, int **wta);
int				new_dad(int **wta, int son);

/*
** ant_nb.c
*/

void			get_ant_nb(t_inputlst **inputlst, int *ant_nb);

/*
** can_be_solved.c
*/

int				can_be_solved(char **tab, int *start, int *end, int *ant_nb);
int				has_a_path(char **tab, int start, int end, int size);

/*
** delete_path.c
*/

void			delete_path_from_tab(char **tab, t_path *path,\
												int size, int end);
void			delete_path(t_path *path);
void			delete_wta(int **wta);
void			clean_pathlst(t_pathlst *pathlst);

/*
** find_path.c
*/

t_pathlst		*find_paths(char **tab, int start, int end, int ant_nb);
t_path			*get_path(char **tab, int start, int end);
t_path			*create_path(int end, int **wta);

/*
** ft_delete_map.c
*/

void			ft_delete_map(char **map);

/*
** ft_mapdup.c
*/

char			**ft_mapdup(char **old);

/*
** ft_mapsize.c
*/

int				ft_mapsize(char **map);

/*
** main.c
*/

void			lem_in(void);

/*
** inputlst.c
*/

void			add_to_inputlst(t_inputlst **inputlst, char *str);
char			*last_input(t_inputlst **inputlst);
void			delete_inputlst(t_inputlst *inputlst);

/*
** parse_map.c
*/

char			**parse_map(t_roomlst **roomlst, int *start,\
									int *end, int *ant_nb);

/*
** path_length.c
*/

int				path_length(t_path *path);
int				paths_capacity(t_pathlst *pathlst);

/*
** print.c
*/

void			print_inputlst(t_inputlst *inputlst);
void			print_roomlst(t_roomlst **roomslst);
void			print_path(t_path *path);
void			print_paths(t_pathlst *pathlst);

/*
** print_solution.c
*/

int				is_empty(t_path *path);
int				are_empty(t_pathlst *pathlst);
void			fill_pathlst(t_pathlst *pathlst, int ant_nb);
t_pathlst		*forward_tmp(t_pathlst *tmp, int min);
void			print_solution(t_roomlst *roomlst,\
										t_pathlst *pathlst, int ant_nb);

/*
** roomlst.c
*/

int				get_roomlst(t_roomlst **roomlst, int *start,\
									int *end, t_inputlst **inpulst);
int				roomlst_size(t_roomlst *roomlst);
void			add_to_roomlst(t_roomlst **roomlst, char **room);
int				is_room(char **room);
int				get_room_index(t_roomlst **roomlst, char *str);

/*
** send_one_in_each.c
*/

char			*get_room_name(t_roomlst *roomlst, int room);
void			print_move(t_path *path, t_roomlst *roomlst, int first);
int				push_path(t_path *path, t_roomlst *roomlst, int first);
int				send_another(t_roomlst *roomlst, t_path *path,\
									int sent, int first);
int				send_one_in_each(t_roomlst *roomlst, t_pathlst *pathlst,\
											int sent, int first);

/*
**	tube.c
*/

int				is_tube(char *str, t_roomlst **roomlst);
int				is_tube_bis(char *str, t_roomlst **roomlst, t_roomlst *start);
char			**get_tab(t_roomlst **roomlst, t_inputlst **inputlst);
char			**create_tube(int size);
void			add_tube(char **map, char *str, t_roomlst **roomlst,\
								t_roomlst *start);

#endif
