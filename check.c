/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 21:04:59 by sding             #+#    #+#             */
/*   Updated: 2018/03/27 21:05:02 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_square_char(char *tet)
{
	int	i;
	int	hash;
	int	dot;
	int	row;

	i = 0;
	hash = 0;
	dot = 0;
	row = 0;
	while (tet[i])
	{
		if (tet[i] == '.')
			dot++;
		if (tet[i] >= 'A' && tet[i] <= 'Z')
			hash++;
		if (tet[i] == '\n')
			row++;
		i++;
	}
	if (hash != 4 || dot != 12 || row != 4)
		return (0);
	return (1);
}

int		ft_check_square_line(char *tet)
{
	int	i;
	int	count;
	int	next_line;

	i = 0;
	count = 0;
	next_line = 4;
	while (tet[i])
	{
		if ((tet[i] >= 'A' && tet[i] <= 'Z') || tet[i] == '.')
			count++;
		if (count > 4)
			return (0);
		if (tet[i] == '\n' && i == next_line)
		{
			count = 0;
			next_line += 5;
		}
		i++;
	}
	return (1);
}

/*
** check if tetris is connected & 2nd and 3rd coor are within 5 gaps
** check the width and height if within the 5 types
*/

int		ft_check_tet_form(char *tet)
{
	int	height;
	int	width;

	height = ft_count_height(tet);
	width = ft_count_width(tet);
	if (!ft_valid_tetris(tet) || !(ft_check_gap(tet)))
		return (0);
	if (width == 0 || height == 0)
		return (0);
	if (height == 1 && width == 4)
		return (1);
	else if (height == 2 && width == 2)
		return (1);
	else if (height == 2 && width == 3)
		return (1);
	else if (height == 3 && width == 2)
		return (1);
	else if (height == 4 && width == 1)
		return (1);
	else
		return (0);
}

int		ft_final_square_check(char **table)
{
	int	i;

	i = 0;
	while (table[i])
	{
		if (!ft_check_square_line(table[i]))
			return (0);
		if (!ft_check_square_char(table[i]))
			return (0);
		if (!ft_check_tet_form(table[i]))
			return (0);
		i++;
	}
	return (1);
}

int		ft_check_file_format(char *tet)
{
	int	i;

	i = 0;
	while (tet[i] != '\0')
	{
		if ((tet[i + 4] == '\n' && tet[i + 9] == '\n' && tet[i + 14] == '\n' &&
			tet[i + 19] == '\n') && (tet[i + 20] == '\n'))
			i += 21;
		else if ((tet[i + 4] == '\n' && tet[i + 9] == '\n' &&
			tet[i + 14] == '\n' && tet[i + 19] == '\n') &&
			(tet[i + 20] == '\0'))
			i += 20;
		else
			return (0);
	}
	i = 0;
	while (tet[i])
	{
		if (tet[i] != '.' && tet[i] != '\n' && tet[i] != '#')
			return (0);
		i++;
	}
	return (1);
}
