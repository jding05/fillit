/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 21:15:00 by sding             #+#    #+#             */
/*   Updated: 2018/04/03 15:02:52 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	**tetriminos;
	char	*readout;
	int		nb_tet;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit input_sample_file\n");
		return (0);
	}
	if (!(readout = read_input(argv[1])))
	{
		ft_putstr("error\n");
		return (0);
	}
	nb_tet = count_nb_tet(readout);
	tetriminos = ft_strsplit_tetrimino(readout, nb_tet);
	if (!tetriminos || !nb_tet || !ft_final_square_check(tetriminos))
	{
		ft_putstr("error\n");
		return (0);
	}
	solver(tetriminos, nb_tet);
	free_table(tetriminos);
	return (0);
}
