/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 20:52:21 by sding             #+#    #+#             */
/*   Updated: 2018/03/27 20:52:23 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "libft/libft.h"
# define BUFF_SIZE 1024

typedef	struct	s_point
{
	int		spot[2];
	int		pos1[2];
	int		pos2[2];
	int		add[2];
	int		next;
}				t_point;

/*
** input.c
*/

char			*read_input(char *file);
void			change_readout(char *readout);
char			*ft_malloc_square(char *str, int j);
char			**ft_strsplit_tetrimino(char *readout, int nb_tet);

/*
** tetrimino.c
*/

int				count_nb_tet(char *tet);
int				ft_valid_tetris(char *tet);
int				ft_count_height(char *tet);
int				ft_count_width(char *tet);
int				ft_check_gap(char *tet);

/*
** check.c
*/

int				ft_check_square_char(char *tet);
int				ft_check_square_line(char *tet);
int				ft_check_tet_form(char *tet);
int				ft_final_square_check(char **table);
int				ft_check_file_format(char *tet);

/*
** coor_single_position.c
*/

void			init_coordinates(int coordinates[4][2]);
int				*tet_single_position(int x, int y);

/*
** coor_position.c
*/

void			ft_get_tet_pos(int position[2], int hash_spot);
void			add_coor(int *first, int *second);
void			coor_gap(int ret[2], int second[2], int first[2]);
int				ft_next_coor_index(char *tet);
void			get_coor_pos(char *tet, t_point *p, int coordinates[4][2],
																	int hash);

/*
** fill_char.c
*/

void			ft_fill_char(char **table, int coor[4][2], char c);
char			ft_get_alpha(char *tet);

/*
** solver.c
*/

int				coor_validator(char **table, int coor[4][2], int side);
int				put_tet(char *tet, char **table, int xy[2], int side);
void			rm_tet(char	*tet, char **table, int xy[2]);
int				fillit(char **table, char **tetriminos, int side, int i);
void			solver(char **tetriminos, int nb);

/*
** table.c
*/
int				ft_get_table_size(int nb);
char			**create_table(int side);
void			print_table(char **table);
void			free_table(char **table);

#endif
