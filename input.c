/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 21:07:48 by sding             #+#    #+#             */
/*   Updated: 2018/04/03 15:04:06 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*read_input(char *file)
{
	char	buf[BUFF_SIZE + 1];
	char	*readout;
	int		fd;
	int		nb_read;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	while ((nb_read = read(fd, buf, BUFF_SIZE)) > 0)
	{
		readout = ft_strndup(buf, nb_read);
		if (!ft_check_file_format(readout))
			return (NULL);
	}
	close(fd);
	return (readout);
}

void	change_readout(char *readout)
{
	char	c;
	int		i;
	int		hash;

	c = 'A';
	i = 0;
	hash = 0;
	while (readout[i])
	{
		if (readout[i] == '#')
		{
			readout[i] = c;
			hash++;
		}
		if (hash == 4)
		{
			c++;
			hash = 0;
		}
		i++;
	}
}

char	*ft_malloc_square(char *str, int j)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)ft_memalloc(sizeof(char) * 21);
	i = 0;
	while (str[i + j] && i < 20)
	{
		word[i] = str[i + j];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_strsplit_tetrimino(char *readout, int nb_tet)
{
	char	**tetriminos;
	int		i;
	int		j;

	if (!readout)
		return (NULL);
	if (!(tetriminos = (char **)ft_memalloc(sizeof(char*) * nb_tet + 1)))
		return (NULL);
	i = 0;
	j = 0;
	change_readout(readout);
	while (i < nb_tet)
	{
		tetriminos[i] = ft_malloc_square(readout, j);
		i++;
		j = j + 20 + 1;
	}
	tetriminos[i] = NULL;
	free(readout);
	return (tetriminos);
}
