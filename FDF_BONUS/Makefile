# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 17:15:20 by mohilali          #+#    #+#              #
#    Updated: 2024/01/20 19:34:36 by mohilali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = fdf.c fdf_parsing.c fdf_utils_one.c fdf_utils_two.c fdf_utils.c fdf_project.c \
	fdf_utils_tree.c fdf_grad_color.c brehensman_algo.c fdf_draw.c fdf_parsing_sec.c\
	fdf_utils_four.c

OBJCT = ${SRC:.c=.o}
CC = cc 
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f
NAME = fdf

all : $(NAME)

$(NAME) : $(OBJCT)
	$(CC) $(OBJCT) -lmlx -framework OpenGL -framework Appkit -o  $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
	$(RM) $(OBJCT)

fclean : clean
	$(RM) $(NAME)
re : all clean
