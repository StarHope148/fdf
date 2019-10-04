# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/02 11:22:48 by jcanteau          #+#    #+#              #
#    Updated: 2019/10/04 15:49:40 by jcanteau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

HEAD = fdf.h

SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INC_PATH = ./includes/

SRC_NAME += main.c
SRC_NAME += parse.c
SRC_NAME += fdf.c
SRC_NAME += mlx.c
SRC_NAME += bresenham.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

LIB = ./libft/libft.a

MLXINC = -I /usr/local/include
MLXLIB = -L /usr/local/lib -lmlx
FRAMEWORK = -framework OpenGL -framework AppKit
CFLAGS = -Wall -Wextra -Werror

$(CC) = gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(MLXINC) $(OBJ) $(MLXLIB) $(FRAMEWORK) $(LIB) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CPPFLAGS) -o $@ -c $<

clean:
	$(RM) -rf $(OBJ_PATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
