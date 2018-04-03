/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 21:12:23 by sding             #+#    #+#             */
/*   Updated: 2018/03/27 21:12:25 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** check four coor positions {{y,x},{y,x},{y,x},{y,x}} one by one.
** if any of y and x in {y,x} is 1. negative 2. over the board side 3. is letter
** if any of 3 conditions above, then the current spot in table isn't available.
*/

int		coor_validator(char **table, int coor[4][2], int side)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (coor[i][0] < 0 || coor[i][1] < 0)
			return (0);
		if (coor[i][0] >= side || coor[i][1] >= side)
			return (0);
		if (table[coor[i][0]][coor[i][1]] != '.')
			return (0);
		i++;
	}
	return (1);
}

int		put_tet(char *tet, char **table, int xy[2], int side)
{
	t_point	*point;
	int		coordinates[4][2];
	char	c;

	c = ft_get_alpha(tet);
	init_coordinates(coordinates);
	point = (t_point *)ft_memalloc(sizeof(t_point));
	point->spot[0] = xy[0];
	point->spot[1] = xy[1];
	get_coor_pos(tet, point, coordinates, 0);
	if (!coor_validator(table, coordinates, side))
		return (0);
	ft_fill_char(table, coordinates, c);
	free(point);
	return (1);
}

void	rm_tet(char *tet, char **table, int xy[2])
{
	t_point	*point;
	int		coordinates[4][2];

	init_coordinates(coordinates);
	point = (t_point *)ft_memalloc(sizeof(t_point));
	point->spot[0] = xy[0];
	point->spot[1] = xy[1];
	get_coor_pos(tet, point, coordinates, 0);
	ft_fill_char(table, coordinates, '.');
	free(point);
}

int		fillit(char **table, char **tetriminos, int side, int i)
{
	int xy[2];

	if (!tetriminos[i])
		return (1);
	xy[0] = 0;
	while (xy[0] < side)
	{
		xy[1] = 0;
		while (xy[1] < side)
		{
			if (put_tet(tetriminos[i], table, xy, side))
			{
				if (fillit(table, tetriminos, side, i + 1))
					return (1);
				else
					rm_tet(tetriminos[i], table, xy);
			}
			xy[1]++;
		}
		xy[0]++;
	}
	return (0);
}

void	solver(char **tetriminos, int nb)
{
	char	**table;
	int		side;

	side = ft_get_table_size(nb * 4);
	table = create_table(side);
	while (!fillit(table, tetriminos, side, 0))
	{
		side++;
		free_table(table);
		table = create_table(side);
	}
	print_table(table);
	free_table(table);
}
