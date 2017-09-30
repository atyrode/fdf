# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofranco <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/21 14:38:17 by ofranco           #+#    #+#              #
#    Updated: 2017/09/30 16:25:08 by atyrode          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

PATH_SRC = ./
PATH_OBJ = ./
PATH_INC = ./includes/

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEAD = ./includes/fdf.h

SRC =	main.c \
		converter.c \
		drawing.c \
		fdf.c \
		window.c \
		image.c \
		new_parse.c 

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))


all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	make -C libft/
	$(CC) $(CFLAGS) -I $(PATH_INC) -c $(addprefix $(PATH_SRC), $(SRC))
	$(CC) -o $(NAME) $(OBJ) -lm -L libft/ -lft minilibx_macos/libmlx.a -framework OpenGL -framework AppKit

.PHONY: clean fclean

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
