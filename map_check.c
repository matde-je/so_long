/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:44:32 by matde-je          #+#    #+#             */
/*   Updated: 2023/09/27 13:49:57 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// check .ber path
void	check_map(char *path)
{
	int	i;

	i = ft_strlen(path);
	if ((path[i - 4] == '.' && path[i - 3] == 'b')
		&& (path[i - 2] == 'e' && path[i - 1] == 'r'))
		check_map2(path);
	else
		error("Invalid map");
	correct_map(path);
}

// sizes of matrix and malloc
void	check_map2(char *path)
{
	int		fd;
	int		size_y;
	int		len;
	char	*gnl;

	fd = open(path, O_RDONLY);
	gnl = get_next_line(fd);
	if (!gnl)
		error("Invalid map");
	len = ft_strlen(gnl) - 1;
	if (len < 2 || gnl[1] == '0')
	{
		free(gnl);
		error("Invalid map");
	}
	size_y = 0;
	while (gnl != NULL)
	{
		free(gnl);
		gnl = get_next_line(fd);
		size_y++;
	}
	free(gnl);
	close(fd);
	check_map3(path, len, size_y);
}

// put in matrix
void	check_map3(char *path, int len, int size_y)
{
	int		fd;
	int		count;

	if (size_y < 2)
		error("Invalid map");
	map()->matrix = malloc(len * size_y);
	map()->size_y = size_y;
	map()->size_x = len;
	count = -1;
	fd = open(path, O_RDONLY);
	while (++count < map()->size_y)
	{
		map()->matrix[count] = rm_nl(get_next_line(fd));
	}
	close(fd);
	check_map4();
}

//check size of lines and walls
void	check_map4(void)
{
	int		count;

	count = 0;
	while (++count < map()->size_y)
	{
		if (ft_strlen(map()->matrix[0]) != ft_strlen(map()->matrix[count]))
			error("Differences in length of map");
	}
	count = -1;
	while (++count < map()->size_x)
	{
		if (map()->matrix[0][count] != '1'
			|| map()->matrix[map()->size_y -1][count] != '1')
			error("Invalid walls of map");
	}
	count = 0;
	while (++count < map()->size_y)
	{
		if (map()->matrix[count][0] != '1'
			|| map()->matrix[count][map()->size_x -1] != '1')
			error("Invalid walls of map");
	}
	check_map5();
}

//check chars
void	check_map5(void)
{
	int	count;
	int	pos;
	int	collect;
	int	escp;

	count = 0;
	pos = 0;
	collect = 0;
	escp = 0;
	check_map56(pos, collect, escp, count);
}
