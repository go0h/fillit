/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:20:56 by astripeb          #+#    #+#             */
/*   Updated: 2019/05/03 21:04:51 by astripeb         ###   ########.fr       */
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

	tet = (char**)malloc(sizeof(char*) * side + 1);
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
