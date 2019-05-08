/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetramino.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 10:44:25 by astripeb          #+#    #+#             */
/*   Updated: 2019/05/08 17:02:04 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRAMINO_H
# define TETRAMINO_H

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "libft.h"

typedef struct	s_tetramino
{
	char				**figure;
	int					width;
	int					height;
	struct s_tetramino	*next;
}				t_tetramino;

# define ONE_TET 21

t_tetramino		*read_file(char *filename);

char			**valid_one_tet(char *one_read_map);

int				basic_check(char **tab);

int				figure_check(char **tab);

int				first_x_y(char **tab, char c);

int				last_x_y(char **tab, char c);

char			**figure_trim(char **tab);

t_tetramino		*ft_newlist(char **figure);

void			ft_listadd(t_tetramino **begin, t_tetramino *new_list);

void			ft_dellist(t_tetramino **begin);

void			ft_list_alpha(t_tetramino *begin);

int				count_tetramino(t_tetramino *begin);

int				ft_sqr(int nbr);

char			**ft_create_map(int side);

int				ft_tetra_square(t_tetramino *tet);

int				ft_tetramino(t_tetramino *tet, char **map);

int				ft_try_on_tet(char **map, char **figure, int y, int x);

void			ft_set_on_map(char **map, char **figure, int y, int x);

void			ft_remove_from_map(char **map, char **figure, int y, int x);

void			ft_print_figure(char **figure);
#endif
