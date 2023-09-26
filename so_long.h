/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:44:56 by matde-je          #+#    #+#             */
/*   Updated: 2023/09/26 14:14:05 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ESC 0xff1b
# define LAK 0xff51
# define RAK 0xff53
# define DAK 0xff54
# define UAK 0xff52

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_map
{
	int		size_x;
	int		size_y;
	int		moves;
	char	**matrix;
}				t_map;

typedef struct s_window
{
	char	*window_ptr;
	char	*mlx_ptr;
	void	*img[200];
}				t_window;

void		error(char	*string);
char		*get_next_line(int fd);
char		*ft_strjoin(char *linha, char *buffer);
void		check_map(char *path);
void		check_map2(char *path);
void		check_map3(char *path);
t_map		*map(void);
int			ft_strlen(char *str);
void		check_map4(void);
void		check_map5(void);
void		check_valid(void);
void		check_map56(int pos, int collect, int escp, int count);
void		check_valid2(int count, int count2);
void		check_valid3(void);
char		*rm_nl(char	*str);
void		correct_map(char *path);
t_window	*window(void);
void		new_window(void);
void		img_func(void);
int			key_handler(int key);
void		move_up(int count, int count2);
void		move_down(int count, int count2);
void		move_left(int count, int count2);
void		move_right(int count, int count2);
int			free_all(int i);
void		window_img(void);
int			collectible(void);
long int	ft_putnbr(long int n);
int			ftint(va_list *arg);
int			ft_strlen(char *string);
int			arg_check(char *string, int i);
int			func(char *string, va_list *args, int i);
int			ft_printf(const char	*string, ...);
void		movements(int count, int count2);

#endif