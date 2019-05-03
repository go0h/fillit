# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astripeb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 17:19:04 by astripeb          #+#    #+#              #
#    Updated: 2019/05/03 21:11:12 by astripeb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJ = *.o

SOURCES =  *.c

all: $(NAME)

bin:
	@$(CC) $(CFLAGS) -c $(SOURCES)

test:
	$(CC) $(CFLAGS) main.c tetra_list_func.c map_generation.c validation.c trimming.c tet_to_char.c -L../libft/ -lft -o valid

$(NAME):
	@$(CC) $(CFLAGS) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(OBJ) $(NAME)

re: fclean all
