/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coor_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 21:16:24 by sding             #+#    #+#             */
/*   Updated: 2018/03/27 21:16:32 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** to find {y,x} of single # in the one 4x4 tetrimino
*/

void	ft_get_tet_pos(int position[2], int hash_spot)
{
	position[0] = hash_spot / 5;
	position[1] = hash_spot % 5;
}

/*
** to add up the gap, to get the next position
*/

void	add_coor(int *first, int *second)
{
	first[0] += second[0];
	first[1] += second[1];
}

/*
** get the gap between the first coor and second coor position
*/

void	coor_gap(int ret[2], int second[2], int first[2])
{
	ret[0] = second[0] - first[0];
	ret[1] = second[1] - first[1];
}

/*
** helper function used in get_coordinates, try to find the next letter position
*/

int		ft_next_coor_index(char *tet)
{
	int i;

	i = 0;
	while (tet[i])
	{
		if (tet[i] >= 'A' && tet[i] <= 'Z')
			return (i + 1);
		i++;
	}
	return (0);
}

/*
** store 4 coor position into 4x2 2D int array {{y,x},{y,x},{y,x},{y,x}}
** first # -> pos1 == pos2, and move the first # to {0,0} position.
** find gap and then add up to the last #, we didn't store position by using
** getting the gap between every coor postion sbtract the first coor postion
** becasue we use p->spot to store the table current location
*/

void	get_coor_pos(char *tet, t_point *p, int coordinates[4][2], int hash)
{
	int	i;

	i = 0;
	while (tet[i] && hash < 4)
	{
		if (tet[i] >= 'A' && tet[i] <= 'Z')
		{
			ft_get_tet_pos(p->pos1, i);
			if (hash == 0)
			{
				p->next = i;
				i--;
			}
			else
				p->next = i + ft_next_coor_index(tet + i + 1);
			ft_get_tet_pos(p->pos2, p->next);
			coor_gap(p->add, p->pos2, p->pos1);
			add_coor(p->spot, p->add);
			coordinates[hash][0] = p->spot[0];
			coordinates[hash][1] = p->spot[1];
			hash++;
		}
		i++;
	}
}
