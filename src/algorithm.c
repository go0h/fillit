/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 21:15:19 by astripeb          #+#    #+#             */
/*   Updated: 2019/05/08 16:54:58 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetramino.h"

int		ft_tetra_square(t_tetramino *tet)
{
	int		side;
	char	**map;

	map = NULL;
	ft_list_alpha(tet);
	side = ft_sqr(4 * count_tetramino(tet));
	while (1)
	{
		if (!(map = ft_create_map(side)))
			return (0);
		if (ft_tetramino(tet, map) == 1)
		{
			ft_print_figure(map);
			ft_free_arr(map);
			break ;
		}
		ft_free_arr(map);
		++side;
	}
	return (1);
}

int		ft_tetramino(t_tetramino *tet, char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (ft_try_on_tet(map, tet->figure, i, j))
			{
				ft_set_on_map(map, tet->figure, i, j);
				if (!tet->next || ft_tetramino(tet->next, map) == 1)
					return (1);
				ft_remove_from_map(map, tet->figure, i, j);
			}
			++j;
		}
		++i;
	}
	return (0);
}

int		ft_try_on_tet(char **map, char **figure, int y, int x)
{
	int i;
	int j;
	int x_temp;

	i = 0;
	x_temp = x;
	while (figure[i])
	{
		if (!map[y + i])
			return (0);
		j = 0;
		x = x_temp;
		while (figure[i][j] != '\0')
		{
			if (!map[y + i][x + j] ||
					(map[y + i][x + j] != '.' && figure[i][j] != '.'))
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}
