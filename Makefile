# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/02 11:22:48 by jcanteau          #+#    #+#              #
#    Updated: 2019/10/06 12:51:51 by jcanteau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

INC_NAME += fdf.h
INC_NAME += keys_define.h

SRC_NAME += main.c
SRC_NAME += parse.c
SRC_NAME += fdf.c
SRC_NAME += mlx.c
SRC_NAME += bresenham.c
SRC_NAME += check.c

OBJ_NAME = $(SRC_NAME:.c=.o)

LIB_NAME = libft.a

INC_PATH = ./includes/
SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
LIB_PATH = ./libft/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
HEAD = $(addprefix $(INC_PATH), $(INC_NAME))
LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))


MLXINC = -I /usr/local/include
MLXLIB = -L /usr/local/lib -lmlx
FRAMEWORK = -framework OpenGL -framework AppKit
MLXFLAG = -I /usr/local/include -L /usr/local/lib -lmlx
CFLAGS = -Wall -Wextra -Werror

$(CC) = gcc

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/.
	$(CC) $(MLXFLAG) $(OBJ) $(FRAMEWORK) $(LIB) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(CPPFLAGS) -o $@ -c $<

clean:
	make clean -C libft/.
	$(RM) -rf $(OBJ_PATH)

fclean: clean
	make clean -C libft/.
	$(RM) $(LIB)
	$(RM) $(NAME) $(NAME).ubuntu

re: fclean all

norm:
	norminette $(SRC) $(HEAD)

ubuntu: $(OBJ)
	make -C libft/.
	$(cc) $(MLXFLAG) $(OBJ) $(LIB) -o $(NAME).ubuntu

.PHONY: clean fclean re all