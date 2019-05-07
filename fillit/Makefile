# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astripeb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 17:19:04 by astripeb          #+#    #+#              #
#    Updated: 2019/05/07 20:57:26 by astripeb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

LIBFT_PATH = ../libft

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -I . -I $(LIBFT_PATH)

OBJ = main.o tetra_list_func.o map_generation.o validation.o\
	  trimming.o tet_to_char.o algorithm.o

SOURCES =  main.c tetra_list_func.c map_generation.c validation.c\
		   trimming.c tet_to_char.c algorithm.c

all: $(NAME)

bin:
	@$(CC) $(CFLAGS) $(LFLAGS) -c $(SOURCES)

$(NAME):
	@$(CC) $(CFLAGS) $(LFLAGS) -c $(SOURCES)
	@$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) -L$(LIBFT_PATH) -lft -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(OBJ) $(NAME)

re: fclean $(NAME)
