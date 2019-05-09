# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astripeb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 17:19:04 by astripeb          #+#    #+#              #
#    Updated: 2019/05/09 14:09:55 by astripeb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

LIBFT_PATH = ./libft
OBJ_PATH = ./obj
SRC_PATH = ./

CFLAGS = -Wall -Wextra -Werror
LFLAGS = -I . -I $(LIBFT_PATH)

SOURCES =  main.c tetra_list_func.c map_generation.c validation.c\
		   trimming.c algorithm.c

OBJ = $(addprefix $(OBJ_PATH)/, $(SOURCES:.c=.o))

all: $(NAME)

$(OBJ_PATH)/%.o:$(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $<

$(NAME): lib $(OBJ)
	@$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) -L$(LIBFT_PATH) -lft -o $(NAME)

lib:
	@make -C $(LIBFT_PATH)

clean:
	@rm -rf $(OBJ_PATH)
	@make -C $(LIBFT_PATH) clean

fclean:
	@rm -rf $(OBJ_PATH) $(NAME)
	@make -C $(LIBFT_PATH) fclean

re: fclean $(NAME)
