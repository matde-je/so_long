# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matilde <matilde@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/22 16:02:27 by matde-je          #+#    #+#              #
#    Updated: 2023/09/27 23:58:50 by matilde          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CC		= cc -g -Wall -Werror -Wextra

SRC	=	main.c							\
		error.c							\
		map_check.c						\
		map_check2.c					\
		mlx_funcs.c						\
		key_handler.c					\
		gnl/get_next_line.c				\
		gnl/get_next_line_utils.c		\
		printf/ft_printf.c				\
		printf/ft_putnbr.c				\
		printf/ft_arg_func.c			\
		printf/ft_int.c					\

OBJ	= $(SRC:.c=.o)
all:	$(NAME)

$(NAME): $(OBJ)
		 $(CC) $(OBJ) -Lminilibx-linux -I/minilibx-linux/mlx.h -L/usr/lib -lmlx -lXext -lX11 -lm -lz -o $(NAME)
//-lX11 -lXext -lmlx
clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean $(NAME)

.PHONY:	all clean fclean re
