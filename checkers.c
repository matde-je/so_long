/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:44:32 by matde-je          #+#    #+#             */
/*   Updated: 2023/07/12 12:17:24 by matde-je         ###   ########.fr       */
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
	len = ft_strlen(gnl);
	size_y = 1;
	while (gnl != NULL)
	{
		gnl = get_next_line(fd);
		size_y++;
	}
	map()->matrix = malloc(len * size_y);
	map()->size_y = size_y;
	map()->size_x = len;
	free(gnl);
	close(fd);
	check_map3(path);
}

// put in matrix
void	check_map3(char *path)
{
	int		fd;
	int		count;
	char	*gnl;

	count = -1;
	fd = open(path, O_RDONLY);
	while (++count < map()->size_y)
	{
		gnl = get_next_line(fd);
		map()->matrix[count] = gnl;
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
			error("Invalid map");
	}
	count = -1;
	while (++count < map()->size_x)
	{
		if (map()->matrix[0][count] != '1'
			&& map()->matrix[map()->size_y -1][count] != '1')
			error("Invalid walls of map");
	}
	count = 0;
	while (++count < map()->size_y)
	{
		if (map()->matrix[count][0] != '1'
			&& map()->matrix[count][map()->size_x -1] != '1')
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
