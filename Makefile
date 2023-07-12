# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/22 16:02:27 by matde-je          #+#    #+#              #
#    Updated: 2023/07/12 12:18:20 by matde-je         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CC		= cc -g -Wall -Werror -Wextra

SRC	=	main.c							\
		error.c							\
		structs.c						\
		checkers.c						\
		checkers2.c						\
		gnl/get_next_line.c				\
		gnl/get_next_line_utils.c		\
		libft/ft_strcpy.c				\
		libft/ft_putstr.c				\
		libft/ft_strdup.c				\
		libft/ft_strlen.c				\

OBJ	= $(SRC:.c=.o)
all:	$(NAME)

$(NAME): $(OBJ)
		 $(CC) $(OBJ) -o $(NAME)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean $(NAME)

.PHONY:	all clean fclean re

# -Lminilibx-linux -I/minilibx-linux/mlx.h -L/usr/lib -lmlx -lXext -lX11 -lm -lz
