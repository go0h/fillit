/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_to_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:43:16 by astripeb          #+#    #+#             */
/*   Updated: 2019/05/03 18:50:45 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetramino.h"

char	tet_to_char(char **tet)
{
	char	c;
	int		i;
	int		j;

	c = 0;
	i = 0;
	while (tet[i])
	{
		j = 0;
		while (tet[i][j])
		{
			if (tet[i][j] == '#')
				c |= 1;
			c <<= 1;
			++j;
		}
		++i;
	}
	return (c >> 1);
}

void	print_octet(char c)
{
	printf("%d", (c >> 7) & 1);
	printf("%d", (c >> 6) & 1);
	printf("%d", (c >> 5) & 1);
	printf("%d ", (c >> 4) & 1);
	printf("%d", (c >> 3) & 1);
	printf("%d", (c >> 2) & 1);
	printf("%d", (c >> 1) & 1);
	printf("%d\n", (c >> 0) & 1);
}
