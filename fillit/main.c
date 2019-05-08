/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 10:56:37 by astripeb          #+#    #+#             */
/*   Updated: 2019/05/08 14:56:42 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetramino.h"

int		main(int argc, char **argv)
{
	t_tetramino		*list;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit source_file");
		return (0);
	}
	if ((list = read_file(argv[1])))
	{
		ft_tetra_square(list);
		ft_dellist(&list);
		return (0);
	}
	ft_putendl("error");
	return (0);
}
