# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 17:15:20 by mohilali          #+#    #+#              #
#    Updated: 2024/01/19 15:49:40 by mohilali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = fdf.c libft_funtions.c parsing.c fdf_help.c fdf_utils_one.c fdf_utils_two.c fdf_utils.c \
	fdf_utils_tree.c draw_projects.c

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
