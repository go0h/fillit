/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 10:43:06 by astripeb          #+#    #+#             */
/*   Updated: 2019/05/05 12:40:55 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetramino.h"

t_tetramino		*read_file(char *filename)
{
	int			fd;
	int			n;
	char		buf[ONE_TET];
	char		**figure;
	t_tetramino	*list;

	list = NULL;
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (NULL);
	while ((n = read(fd, buf, ONE_TET)) > 0)
	{
		buf[n] = '\0';
		if (!(figure = valid_one_tet(buf)))
		{
			ft_dellist(&list);
			return (NULL);
		}
		ft_listadd(&list, figure);
		if (!(list))
		{
			ft_dellist(&list);
			return (NULL);
		}
	}
	return (list);
}

char			**valid_one_tet(char *buf)
{
	char	**tab;

	if (!(tab = ft_strsplit(buf, '\n')))
		return (NULL);
	if (!(basic_check(tab)) || !(figure_check(tab)))
	{
		ft_free_arr(tab);
		return (NULL);
	}
	if (!(tab = figure_trim(tab)))
		return (NULL);
	return (tab);
}

int				basic_check(char **tab)
{
	int i;
	int j;
	int	count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		if (i > 3)
			return (0);
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (j > 3 || (tab[i][j] != '#' && tab[i][j] != '.'))
				return (0);
			if (tab[i][j] == '#')
				++count;
			++j;
		}
		if (j != 4)
			return (0);
		++i;
	}
	return (count != 4 ? 0 : 1);
}

int				figure_check(char **tab)
{
	int i;
	int j;
	int count;

	count = 0;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (i > 0 && tab[i][j] == '#' && tab[i - 1][j] == '#')
				++count;
			if (i < 3 && tab[i][j] == '#' && tab[i + 1][j] == '#')
				++count;
			if (j > 0 && tab[i][j] == '#' && tab[i][j - 1] == '#')
				++count;
			if (j < 3 && tab[i][j] == '#' && tab[i][j + 1] == '#')
				++count;
			++j;
		}
		++i;
	}
	return ((count == 6 || count == 8) ? 1 : 0);
}
