# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/22 16:02:27 by matde-je          #+#    #+#              #
#    Updated: 2023/07/19 19:20:11 by matde-je         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CC		= cc -g -Wall -Werror -Wextra -fsanitize=address 

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

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean $(NAME)

.PHONY:	all clean fclean re
