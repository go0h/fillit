/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:20:56 by astripeb          #+#    #+#             */
/*   Updated: 2019/05/05 17:24:31 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetramino.h"

int		ft_sqr(int	nbr)
{
	int		n;

	n = nbr / 2;
	while (n)
	{
		if (n * n <= nbr)
			return (n);
		--n;
	}
	return (0);
}

char	**ft_create_map(int side)
{
	char	**tet;
	int		i;

	tet = (char**)malloc(sizeof(char*) * (side + 1));
	if (!tet)
		return (NULL);
	i = 0;
	while (i < side)
	{
		tet[i] = ft_strnew(side);
		if (!tet[i])
			ft_free_arr(tet);
		ft_memset(tet[i], 46, (size_t)side);
		++i;
	}
	tet[i] = NULL;
	return (tet);
}

void	ft_set_on_map(char **map, char **figure, int y, int x)
{
	int i;
	int j;
	int	x_temp;
	
	i = 0;
	x_temp = x;
	while (map[y + i] && figure[i])
	{
		j = 0;
		x = x_temp;
		while (map[y + i][x + j] && figure[i][j])
		{
			if (figure[i][j] != '.')
				map[y + i][x + j] = figure[i][j];
			++j;
		}
		++i;
	}
}

void	ft_remove_from_map(char **map, char **figure, int y, int x)
{
	int i;
	int j;
	int	x_temp;
	
	x_temp = x;	
	i = 0;
	while (map[y + i] && figure[i])
	{
		j = 0;
		x = x_temp;
		while (map[y + i][x + j] && figure[i][j])
		{
			if (figure[i][j] != '.')
				map[y + i][x + j] = '.';
			++j;
		}
		++i;
	}
}
