/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:57:02 by matde-je          #+#    #+#             */
/*   Updated: 2023/07/12 19:32:00 by matde-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//check chars
void	check_map56(int pos, int collect, int escp, int count)
{
	int	count2;

	count2 = -1;
	while (++count < map()->size_y)
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
	count = 0;
	count2 = -1;
	check_valid(count, count2);
}

//find start position
void	check_valid(int count, int count2)
{
	while (++count < map()->size_y)
	{
		count2 = 0;
		while (++count2 < map()->size_x)
		{
			if (map()->matrix[count][count2] == 'P')
				break ;
		}
	}
	create_map();
	check_valid2(count, count2);
	count = 0;
	check_valid3(count, count2);
}

//create map_path
void	create_map(void)
{
	int	count2;
	int	count;

	count = -1;
	map_path()->matrix = malloc(map()->size_y * map()->size_x);
	while (++count < map()->size_y)
	{
		count2 = -1;
		while (++count2 < map()->size_x)
			map_path()->matrix[count][count2] = map()->matrix[count][count2];
	}
	
}

//check valid path and transform them to letter T
void	check_valid2(int count, int count2)
{
	map_path()->matrix[count][count2] = 'T';
	if (map_path()->matrix[count][count2 + 1] != '1' && map_path()->matrix[count][count2 + 1] != 'T')
		check_valid2(count, count2 + 1);
	if (map_path()->matrix[count][count2 - 1] != '1' && map_path()->matrix[count][count2 - 1] != 'T')
		check_valid2(count, count2 - 1);
	if (map_path()->matrix[count + 1][count2] != '1' && map_path()->matrix[count + 1][count2] != 'T')
		check_valid2(count + 1, count2);
	if (map_path()->matrix[count - 1][count2] != '1' && map_path()->matrix[count - 1][count2] != 'T')
		check_valid2(count - 1, count2);
}

// check valid path
void	check_valid3(int count, int count2)
{
	while (++count < map()->size_y)
	{
		count2 = 0;
		while (++count2 < map()->size_x)
		{
			if (map()->matrix[count][count2] == 'E' || map()->matrix[count][count2] == 'C')
				error("No path possible");
		}
	}
	count = -1;
	while (++count < map()->size_x)
	{
		free(map_path()->matrix[count]);
	}
	free(map_path()->matrix);
}
