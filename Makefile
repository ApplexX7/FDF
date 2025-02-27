# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 17:15:20 by mohilali          #+#    #+#              #
#    Updated: 2025/02/27 15:45:40 by mohilali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src/fdf_bonus.c src/fdf_parsing_bonus.c src/fdf_utils_one_bonus.c \
	src/fdf_utils_two_bonus.c src/fdf_utils_bonus.c src/fdf_utils_tree_bonus.c \
	src/fdf_grad_color_bonus.c src/fdf_brehensman_bonus.c src/fdf_draw_bonus.c \
	src/fdf_parsing_sec_bonus.c src/fdf_utils_four_bonus.c src/fdf_rotation_bonus.c \
	src/fdf_isoproject_bonus.c src/fdf_centre_bonus.c src/fdf_keybord_bonus.c \
	src/fdf_iniate_bonus.c src/fdf_keybordsec_bonus.c src/fdf_menu_bonus.c

OBJCT = ${SRC:.c=.o}

CC = cc 
CFLAGS = -Wall -Werror -Wextra

RM = rm -f
NAME = FDF

HEADER_NAME = src/fdf_bonus.h
MLXFLAGS = -Lminilibx-linux -lmlx -lX11 -lXext -lm
MLX_LIB = ./minilibx-linux


all : $(NAME)

%.o : %.c $(HEADER_NAME)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJCT)
	$(CC) $(CFLAGS) $(OBJCT) $(MLXFLAGS) -o $(NAME)

clean :
	$(RM) $(OBJCT)

fclean : clean
	$(RM) $(NAME)

re : all clean
