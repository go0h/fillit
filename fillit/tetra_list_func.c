/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra_list_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 18:50:13 by astripeb          #+#    #+#             */
/*   Updated: 2019/05/01 20:31:31 by astripeb         ###   ########.fr       */
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
	new_list->size_x = last_x_y(figure, 'x') - first_x_y(figure, 'x') + 1;
	new_list->size_y = last_x_y(figure, 'y') - first_x_y(figure, 'y') + 1;
	new_list->next = NULL;
	return (new_list);
}

void			ft_listadd(t_tetramino **begin, char **figure)
{
	t_tetramino *temp;
	
	if (!*begin)
		*begin = ft_newlist(figure);
	else
	{
		temp = *begin;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = ft_newlist(figure);
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

void			ft_print_list(t_tetramino **begin)
{
	t_tetramino *temp;

	temp = *begin;
	while (temp)
	{
		ft_print_figure(temp->figure);
		printf("size_x = %d, size_y = %d\n\n", temp->size_x, temp->size_y);
		temp = temp->next;
	}
}
