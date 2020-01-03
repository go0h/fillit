# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astripeb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 17:19:04 by astripeb          #+#    #+#              #
#    Updated: 2020/01/03 15:59:56 by astripeb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			:= fillit
LIBFT			:= libft
SRC_DIR 		:= ./src
INC_DIR			:= ./inc
LIBFT_DIR 		:= ./libft
OBJ_DIR 		:= ./obj

CC 				:= gcc
CFLAGS 			:= -Wall -Wextra -Werror
LFLAGS 			:= -I $(INC_DIR) -I $(LIBFT_DIR)

LIB				:= -L $(LIBFT_DIR) -lft

HEADERS			:= tetramino.h

SRCS			:= main.c tetra_list_func.c map_generation.c validation.c\
				trimming.c algorithm.c

OBJ 			:= $(SRCS:.c=.o)

all: lib $(NAME)

vpath %.c $(SRC_DIR)
vpath %.h $(INC_DIR)
vpath %.o $(OBJ_DIR)
vpath %.a $(LIBFT_DIR)

$(OBJ):%.o:%.c $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(LFLAGS) -o $(OBJ_DIR)/$@ -c $<

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(LFLAGS) $(addprefix $(OBJ_DIR)/, $(OBJ)) $(LIB) -o $@

lib:
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) $@ -C $(LIBFT_DIR)

fclean:
	rm -rf $(OBJ_DIR) $(NAME)
	$(MAKE) $@ -C $(LIBFT_DIR)

re: fclean all

.SILENT: all clean fclean re $(NAME) $(OBJ_DIR) $(OBJ) lib

.PHONY: all clean fclean re $(NAME) $(OBJ)
