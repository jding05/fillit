/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 21:56:08 by sding             #+#    #+#             */
/*   Updated: 2018/03/27 21:56:17 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** fill the table w/ char 'c', either use in fill letter 'A' 'B' 'C' in put_tet
** or rm_tet and fill it with '.'
*/

void	ft_fill_char(char **table, int coor[4][2], char c)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		table[coor[i][0]][coor[i][1]] = c;
		i++;
	}
}

/*
** to get the letter of each 4x4 tetris ('A', 'B', 'C', .....)
*/

char	ft_get_alpha(char *tet)
{
	char	c;

	c = 'A';
	while (*tet)
	{
		if (*tet != '.' && *tet != '\n')
		{
			c = *tet;
			return (c);
		}
		tet++;
	}
	return (0);
}
