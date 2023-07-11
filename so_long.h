/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:44:56 by matde-je          #+#    #+#             */
/*   Updated: 2023/07/11 22:11:43 by matde-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ESC 53
# define ENTER 36
# define WKEY 13
# define AKEY 0
# define SKEY 1
# define DKEY 2
# define PIXELS 64

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "minilibx-linux/mlx.h"

typedef struct s_map
{
	int		size_x;
	int		size_y;
	char	**matrix;
}				t_map;

void			error(char	*string);
void			ft_putstr(char *str);
char			*get_next_line(int fd);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strjoin(char *linha, char *buffer);
char			*ft_strdup(char *s1);
void			check_map(char *path);
void			check_map2(char *path);
void			check_map3(char *path);
t_map			*map(void);
int				ft_strlen(char *str);
void			check_map4(void);

#endif