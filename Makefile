# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/02 11:22:48 by jcanteau          #+#    #+#              #
#    Updated: 2019/11/01 14:21:25 by jcanteau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

INC_NAME += fdf.h
INC_NAME += keys.h
INC_NAME += colors.h

SRC_NAME += main.c
SRC_NAME += fdf.c
SRC_NAME += bresenham.c
SRC_NAME += check.c
SRC_NAME += parse.c
SRC_NAME += mlx_start_up.c
SRC_NAME += key_hook.c
SRC_NAME += image.c
SRC_NAME += projection.c
SRC_NAME += color.c
SRC_NAME += menu.c
SRC_NAME += init_tool.c
SRC_NAME += parse_tool.c
SRC_NAME += controls.c

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

FRAMEWORK = -framework OpenGL -framework AppKit
MLXFLAG = -I /usr/local/include -L /usr/local/lib -lmlx
CFLAGS = -Wall -Wextra -Werror

$(CC) = gcc

###############################################################################

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/.
	$(CC) $(CFLAGS) $(MLXFLAG) $(OBJ) $(FRAMEWORK) $(LIB) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEAD)
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -o $@ -c $< 

clean:
	make clean -C $(LIB_PATH)
	$(RM) -rf $(OBJ_PATH)

fclean: clean debug_clean
	$(RM) $(LIB)
	$(RM) $(NAME) $(NAME).ubuntu

re: fclean all

debug:
	make -C $(LIB_PATH)
	$(CC) -g3 -fsanitize=address,undefined $(CFLAGS) $(SRC) $(LIB) $(MLXFLAG) $(FRAMEWORK)

debug_clean:
	$(RM) -rf a.out a.out.DSYM
	
norm:
	norminette $(SRC) $(HEAD) $(LIB_PATH)

ubuntu: $(OBJ)
	make -C $(LIB_PATH)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME) libmlx.a -L/usr/lib -Imlx -lXext -lX11 -lm
#	$(CC) $(CFLAGS) $(MLXFLAG) $(OBJ) $(LIB) -o $(NAME) -lmlx -lXext -lX11 -lm

install_mlx:
	sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev	

.PHONY: clean fclean re all debug debug_clean norm ubuntu