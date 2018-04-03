/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 21:22:26 by sding             #+#    #+#             */
/*   Updated: 2018/03/27 21:22:34 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_get_table_size(int nb)
{
	int	side;

	side = 0;
	if (nb < 0)
		return (0);
	while ((side * side) < nb)
		side += 1;
	return (side);
}

char	**create_table(int side)
{
	char	**table;
	int		i;
	int		j;

	i = 0;
	table = (char **)ft_memalloc(sizeof(char *) * side + 1);
	while (i < side)
	{
		j = 0;
		table[i] = (char *)ft_memalloc(sizeof(char) * side + 1);
		while (j < side)
		{
			table[i][j] = '.';
			j++;
		}
		table[i][j] = '\0';
		i++;
	}
	table[i] = NULL;
	return (table);
}

void	print_table(char **table)
{
	int y;
	int x;

	y = 0;
	while (table[y])
	{
		x = 0;
		while (table[y][x])
		{
			ft_putchar(table[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

void	free_table(char **table)
{
	int i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		table[i] = NULL;
		i++;
	}
	free(table);
	table = NULL;
}