# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/02 11:22:48 by jcanteau          #+#    #+#              #
#    Updated: 2019/10/08 18:40:04 by jcanteau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

INC_NAME += fdf.h
INC_NAME += keys_define.h

SRC_NAME += main.c
SRC_NAME += fdf.c
SRC_NAME += mlx.c
SRC_NAME += bresenham.c
SRC_NAME += check.c
SRC_NAME += create_map.c
SRC_NAME += mlx_func.c
SRC_NAME += key_hook.c

OBJ_NAME = $(SRC_NAME:.c=.o)

LIB_NAME = libft.a

INC_PATH = ./includes/
SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
LIB_PATH = ./libft/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
HEAD = $(addprefix -I $(INC_PATH), $(INC_NAME))
LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))


MLXINC = -I /usr/local/include
MLXLIB = -L /usr/local/lib -lmlx
FRAMEWORK = -framework OpenGL -framework AppKit
MLXFLAG = -I /usr/local/include -L /usr/local/lib -lmlx
CFLAGS = -Wall -Wextra -Werror

$(CC) = gcc

###############################################################################

all: $(NAME)

$(NAME): $(OBJ) 
	make -C libft/.
	$(CC) $(CFLAGS) $(MLXFLAG) $(OBJ) $(FRAMEWORK) $(LIB) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(HEAD) -o $@ -c $< 

clean:
	make clean -C $(LIB_PATH)
	$(RM) -rf $(OBJ_PATH)

fclean: clean debug_clean
	make clean -C $(LIB_PATH)
	$(RM) $(LIB)
	$(RM) $(NAME) $(NAME).ubuntu

re: fclean all

debug:
	make -C $(LIB_PATH)
	$(CC) -g3 -fsanitize=address,undefined $(CFLAGS) $(SRC) $(LIB) $(MLXFLAG) $(FRAMEWORK)

debug_clean:
	$(RM) -rf a.out a.out.DSYM
	
norm:
	norminette $(SRC) $(HEAD)

ubuntu: $(OBJ)
	make -C $(LIB_PATH)
	$(CC) $(MLXFLAG) $(OBJ) $(LIB) -o $(NAME)

.PHONY: clean fclean re all debug debug_clean norm ubuntu