# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astripeb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 17:19:04 by astripeb          #+#    #+#              #
#    Updated: 2019/05/08 19:50:54 by astripeb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

LIBFT_PATH = ./libft

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -I . -I $(LIBFT_PATH)

SOURCES =  main.c tetra_list_func.c map_generation.c validation.c\
		   trimming.c algorithm.c

OBJ = $(SOURCES:.c=.o)

all: $(NAME)

bin:
	@$(CC) $(CFLAGS) $(LFLAGS) -c $(SOURCES)

$(NAME): lib bin
	@$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) -L$(LIBFT_PATH) -lft -o $(NAME)

lib:
	@make -C $(LIBFT_PATH)

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT_PATH) clean

fclean:
	@rm -f $(OBJ) $(NAME)
	@make -C $(LIBFT_PATH) fclean

re: fclean $(NAME)
