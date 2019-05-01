/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trimming.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:59:07 by astripeb          #+#    #+#             */
/*   Updated: 2019/05/01 18:21:57 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetramino.h"

int		first_x_y(char **tab, char c)
{
	int i;
	int j;
	int temp;

	i = 0;
	temp = 4;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == '#' && c == 'x' && j < temp)
				temp = j;
			if (tab[i][j] == '#' && c == 'y' && i < temp)
				temp = i;
			++j;
		}
		++i;
	}
	return (temp);
}

int		last_x_y(char **tab, char c)
{
	int i;
	int j;
	int temp;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == '#' && c == 'x' && j > temp)
				temp = j;
			if (tab[i][j] == '#' && c == 'y')
				temp = i;
			++j;
		}
		++i;
	}
	return (temp);
}

char	**figure_trim(char **tab)
{
	int		size_y;
	int		size_x;
	int		i;
	char	**figure;

	size_y = last_x_y(tab, 'y') - first_x_y(tab, 'y') + 1;
	size_x = last_x_y(tab, 'x') - first_x_y(tab, 'x') + 1;
	if (!(figure = (char**)malloc(sizeof(char*) * (size_y + 1))))
		return (NULL);
	i = 0;
	while (i < size_y)
	{
		if (!(figure[i] = ft_strnew(size_x)))
		{
			ft_free_arr(figure);
			return (NULL);
		}
		ft_strncpy(figure[i],\
				&tab[first_x_y(tab, 'y') + i][first_x_y(tab, 'x')],\
				(size_t)size_x);
		++i;
	}
	ft_free_arr(tab);
	figure[i] = NULL;
	return (figure);
}

void	ft_print_figure(char **figure)
{
	int i;

	i = 0;
	while (figure[i])
	{
		ft_putendl(figure[i]);
		++i;
	}
	ft_putchar('\n');
}
