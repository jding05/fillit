/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 21:26:50 by sding             #+#    #+#             */
/*   Updated: 2018/03/27 21:26:51 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_nb_tet(char *tet)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tet[i])
	{
		if (tet[i] == '\n' && (tet[i + 1] == '\n' || tet[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

int		ft_valid_tetris(char *tet)
{
	int	i;
	int	connected;

	i = 0;
	connected = 0;
	while (tet[i])
	{
		if (tet[i] >= 'A' && tet[i] <= 'Z')
		{
			if ((tet[i - 1] >= 'A' && tet[i - 1] <= 'Z') ||
				(tet[i + 1] >= 'A' && tet[i + 1] <= 'Z') ||
				(tet[i - 5] >= 'A' && tet[i - 5] <= 'Z') ||
				(tet[i + 5] >= 'A' && tet[i + 5] <= 'Z'))
				connected++;
			if (connected == 4)
				return (1);
		}
		i++;
	}
	return (0);
}

int		ft_count_height(char *tet)
{
	int	i;
	int	height;
	int	next_line;
	int	check;

	i = 0;
	height = 0;
	next_line = 4;
	while (tet[i])
	{
		check = 0;
		while (i < next_line)
		{
			if (tet[i] >= 'A' && tet[i] <= 'Z')
				check = 1;
			i++;
		}
		if (check)
			height++;
		next_line += 5;
		i++;
	}
	return (height);
}

int		ft_count_width(char *tet)
{
	int i;
	int width;
	int column_gap;

	i = 0;
	width = 0;
	column_gap = 0;
	while (i < 4)
	{
		if ((tet[i] >= 'A' && tet[i] <= 'Z') ||
			(tet[i + 5] >= 'A' && tet[i + 5] <= 'Z') ||
			(tet[i + 10] >= 'A' && tet[i + 10] <= 'Z') ||
			(tet[i + 15] >= 'A' && tet[i + 10] <= 'Z'))
		{
			width++;
			if (column_gap > 0)
				return (0);
		}
		else if (width > 0)
			column_gap++;
		i++;
	}
	return (width);
}

int		ft_check_gap(char *tet)
{
	int	i;
	int	hash;
	int	gap;

	i = 0;
	hash = 0;
	gap = 0;
	while (tet[i])
	{
		if (tet[i] >= 'A' && tet[i] <= 'Z')
			hash++;
		if (hash == 2 && tet[i] >= 'A' && tet[i] <= 'Z')
		{
			while ((tet[i + 1 + gap] == '.' || tet[i + 1 + gap] == '\n') &&
					tet[i + gap])
				gap++;
			if (gap > 5)
				return (0);
		}
		i++;
	}
	return (1);
}
