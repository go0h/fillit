/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 10:56:37 by astripeb          #+#    #+#             */
/*   Updated: 2019/05/03 22:15:40 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetramino.h"

int		main(int argc, char **argv)
{
	int				i;
	t_tetramino		*list;

	/*на время тестирования
	 * if (argc != 2)
	{
		ft_putendl("usage: ./fillit source_file");
		return (0);
	}*/
	i = 1;
	while (i < argc)
	{
		//printf("%s\n", argv[i]);
		list = read_file(argv[i]);
		if (list)
		{
			ft_print_list(&list);
		}
		else
			printf("file %s: invalid tetramino\n", argv[i]);
		++i;
	}
	ft_dellist(&list);
	return (0);
}
