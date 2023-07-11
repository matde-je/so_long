#ifndef SO_LONG_H
# define SO_LONG_H

# define ESC 53
# define ENTER 36
# define WKEY 13
# define AKEY 0
# define SKEY 1
# define DKEY 2

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
//	int		moves;
//	char	*map_line;
	char	**matrix;
}				t_map;

void			error(char	*string);
void			ft_putstr(char *str);
char			*get_next_line(int fd);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strjoin(char *linha, char *buffer);
static size_t	ft_strlen(const char *str);
char			*ft_strdup(char *s1);

#endif