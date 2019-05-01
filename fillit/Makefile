# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astripeb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 17:19:04 by astripeb          #+#    #+#              #
#    Updated: 2019/05/01 19:21:34 by astripeb         ###   ########.fr        #
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
	$(CC) $(CFLAGS) main.c tetra_list_func.c validation.c trimming.c -L../libft/ -lft -o valid

$(NAME):
	@$(CC) $(CFLAGS) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(OBJ) $(NAME)

re: fclean all
