/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:57:02 by matde-je          #+#    #+#             */
/*   Updated: 2023/07/12 13:47:16 by matde-je         ###   ########.fr       */
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

//check valid path
void	check_valid(int count, int count2)
{
	while (++count < map()->size_y)
	{
		while (++count2 < map()->size_x)
		{
			if (map()->matrix[count][count2] == 'P')
			{
				if ((map()->matrix[count][count2 +1] == '1'
					|| map()->matrix[count][count2 +1] != 'E')
					&& (map()->matrix[count][count2 -1] != '1'
					|| map()->matrix[count][count2 +1] != 'E')
					&& (map()->matrix[count -1][count2] != '1'
					|| map()->matrix[count -1][count2] != 'E')
					&& (map()->matrix[count -1][count2] != '1'
					|| map()->matrix[count -1][count2] != 'E'))
					error("Invalid path in map");
				break ;
			}
		}
	}
	check_valid2(count, count2);
}

void	check_valid2(int count, int count2)
{
	while (count < map()->size_y)
	{
		while (count2 < map()->size_x)
		{
			if ((map()->matrix[count][count2 +1] == '1'
				|| map()->matrix[count][count2 +1] != 'E')
				&& (map()->matrix[count][count2 -1] != '1'
				|| map()->matrix[count][count2 +1] != 'E')
				&& (map()->matrix[count -1][count2] != '1'
				|| map()->matrix[count -1][count2] != 'E')
				&& (map()->matrix[count -1][count2] != '1'
				|| map()->matrix[count -1][count2] != 'E'))
				error("Invalid path in map");
		}
	}
}
