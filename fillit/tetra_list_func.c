/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra_list_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 18:50:13 by astripeb          #+#    #+#             */
/*   Updated: 2019/05/08 15:03:24 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetramino.h"

t_tetramino		*ft_newlist(char **figure)
{
	t_tetramino	*new_list;

	if (!figure)
		return (NULL);
	if (!(new_list = (t_tetramino*)malloc(sizeof(t_tetramino))))
		return (NULL);
	new_list->figure = figure;
	new_list->octet = tet_to_char(figure);
	new_list->width = last_x_y(figure, 'x') - first_x_y(figure, 'x') + 1;
	new_list->height = last_x_y(figure, 'y') - first_x_y(figure, 'y') + 1;
	new_list->y = 0;
	new_list->x = 0;
	new_list->next = NULL;
	return (new_list);
}

void			ft_listadd(t_tetramino **begin, t_tetramino *new)
{
	t_tetramino *temp;

	if (new)
	{
		if (!*begin)
			*begin = new;
		else
		{
			temp = *begin;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new;
		}
	}
}

void			ft_dellist(t_tetramino **begin)
{
	t_tetramino *temp_1;
	t_tetramino *temp_2;

	temp_1 = *begin;
	while (temp_1)
	{
		temp_2 = temp_1;
		temp_1 = temp_1->next;
		ft_free_arr(temp_2->figure);
		free(temp_2);
	}
	begin = NULL;
}

int				count_tetramino(t_tetramino *begin)
{
	int i;

	i = 0;
	while (begin)
	{
		++i;
		begin = begin->next;
	}
	return (i);
}

void			ft_list_alpha(t_tetramino *begin)
{
	char		c;
	int			i;
	int			j;

	c = 'A';
	while (begin)
	{
		i = 0;
		while (begin->figure[i])
		{
			j = 0;
			while (begin->figure[i][j])
			{
				if (begin->figure[i][j] == '#')
					begin->figure[i][j] = c;
				++j;
			}
			++i;
		}
		begin = begin->next;
		++c;
	}
}

void			ft_print_list(t_tetramino **begin)
{
	t_tetramino *temp;

	temp = *begin;
	while (temp)
	{
		ft_print_figure(temp->figure);
		printf("w = %d\nh = %d\n", temp->width, temp->height);
		print_octet(temp->octet);
		printf("%d\n\n", temp->octet);
		temp = temp->next;
	}
}
