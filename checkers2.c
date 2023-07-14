/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:57:02 by matde-je          #+#    #+#             */
/*   Updated: 2023/07/14 22:01:00 by matde-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//check chars
void	check_map56(int pos, int collect, int escp, int count)
{
	int	count2;

	while (++count < map()->size_y - 1)
	{
		count2 = 0;
		while (++count2 < map()->size_x)
		{
			if (map()->matrix[count][count2] == 'P')
				pos += 1;
			else if (map()->matrix[count][count2] == 'C')
				collect += 1;
			else if (map()->matrix[count][count2] == 'E')
				escp += 1;
			else if (map()->matrix[count][count2] != '0'
					&& map()->matrix[count][count2] != '1')
				error("Invalid contents in map");
		}
	}
	if (pos != 1 || collect < 1 || escp != 1)
		error("Invalid contents in map");
	check_valid();
}

//find start position
void	check_valid(void)
{
	int	count;
	int	count2;
	int	x;
	int	y;

	count = 0;
	while (++count < map()->size_y)
	{
		count2 = 0;
		while (++count2 < map()->size_x - 1)
		{
			if (map()->matrix[count][count2] == 'P')
			{
				y = count;
				x = count2;
				break ;
			}
		}
	}
	check_valid2(y, x);
	check_valid3();
}

//check valid path and transform it to letter T
void	check_valid2(int count, int count2)
{
	map()->matrix[count][count2] = 'T';
	if (map()->matrix[count][count2 + 1] != '1'
		&& map()->matrix[count][count2 + 1] != 'T')
		check_valid2(count, count2 + 1);
	if (map()->matrix[count][count2 - 1] != '1'
		&& map()->matrix[count][count2 - 1] != 'T')
		check_valid2(count, count2 - 1);
	if (map()->matrix[count + 1][count2] != '1'
		&& map()->matrix[count + 1][count2] != 'T')
		check_valid2(count + 1, count2);
	if (map()->matrix[count - 1][count2] != '1'
		&& map()->matrix[count - 1][count2] != 'T')
		check_valid2(count - 1, count2);
}

// check valid path
void	check_valid3(void)
{
	int	count;
	int	count2;

	count = 0;
	count2 = 0;
	while (++count < map()->size_y)
	{
		count2 = 0;
		while (++count2 < map()->size_x)
		{
			if (map()->matrix[count][count2] == 'E'
				|| map()->matrix[count][count2] == 'C')
				error("No path possible");
		}
	}
}

void	correct_map(char *path)
{
	int		fd;
	int		count;

	count = -1;
	while (++count < map()->size_y)
		free(map()->matrix[count]);
	count = -1;
	fd = open(path, O_RDONLY);
	while (++count < map()->size_y)
		map()->matrix[count] = rm_nl(get_next_line(fd));
	close(fd);
}
