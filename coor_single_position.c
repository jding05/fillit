/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coor_single_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 21:42:46 by sding             #+#    #+#             */
/*   Updated: 2018/03/27 21:51:21 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	init_coordinates(int coordinates[4][2])
{
	int	x;
	int	y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 2)
		{
			coordinates[x][y] = 0;
			y++;
		}
		x++;
	}
}

int		*tet_single_position(int x, int y)
{
	int	*position;

	position = (int *)ft_memalloc(sizeof(int) * 2);
	position[0] = x;
	position[1] = y;
	return (position);
}
