/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:58:20 by matde-je          #+#    #+#             */
/*   Updated: 2023/09/26 13:15:49 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handler(int key)
{
	int	count;
	int	count2;

	count = -1;
	count2 = -1;
	if (key == ESC)
		free_all(0);
	else if (key == UAK)
		move_up(count, count2);
	else if (key == LAK)
		move_left(count, count2);
	else if (key == RAK)
		move_right(count, count2);
	else if (key == DAK)
		move_down(count, count2);
	return (0);
}

void	move_up(int count, int count2)
{
	while (++count < map()->size_y)
	{
		count2 = -1;
		while (++count2 < map()->size_x)
		{
			if (map()->matrix[count][count2] == 'P')
			{
				if (map()->matrix[count -1][count2] == '1'
					|| (map()->matrix[count -1][count2] == 'E'
					&& collectible() == 1))
					return ;
				if (map()->matrix[count -1][count2] == 'E'
					&& collectible() == 0)
					free_all(0);
				map()->matrix[count][count2] = '0';
				mlx_put_image_to_window(window()->mlx_ptr, \
				window()->window_ptr, window()->img['0'], \
				count2 * 64, count * 64);
				movements(count -1, count2);
				return ;
			}
		}
	}
}

void	move_down(int count, int count2)
{
	while (++count < map()->size_y)
	{
		count2 = -1;
		while (++count2 < map()->size_x)
		{
			if (map()->matrix[count][count2] == 'P')
			{
				if (map()->matrix[count +1][count2] == '1'
					|| (map()->matrix[count +1][count2] == 'E'
					&& collectible() == 1))
					return ;
				if (map()->matrix[count +1][count2] == 'E'
					&& collectible() == 0)
					free_all(0);
				map()->matrix[count][count2] = '0';
				mlx_put_image_to_window(window()->mlx_ptr, \
				window()->window_ptr, window()->img['0'], \
				count2 * 64, count * 64);
				movements(count +1, count2);
				return ;
			}
		}
	}
}

void	move_left(int count, int count2)
{
	while (++count < map()->size_y)
	{
		count2 = -1;
		while (++count2 < map()->size_x)
		{
			if (map()->matrix[count][count2] == 'P')
			{
				if (map()->matrix[count][count2 -1] == '1'
					|| (map()->matrix[count][count2 -1] == 'E'
					&& collectible() == 1))
					return ;
				if (map()->matrix[count][count2 -1] == 'E'
					&& collectible() == 0)
					free_all(0);
				map()->matrix[count][count2] = '0';
				mlx_put_image_to_window(window()->mlx_ptr, \
				window()->window_ptr, window()->img['0'], \
				count2 * 64, count * 64);
				movements(count, count2 -1);
				return ;
			}
		}
	}
}

void	move_right(int count, int count2)
{
	while (++count < map()->size_y)
	{
		count2 = -1;
		while (++count2 < map()->size_x)
		{
			if (map()->matrix[count][count2] == 'P')
			{
				if (map()->matrix[count][count2 +1] == '1'
					|| (map()->matrix[count][count2 +1] == 'E'
					&& collectible() == 1))
					return ;
				if (map()->matrix[count][count2 +1] == 'E'
					&& collectible() == 0)
					free_all(0);
				map()->matrix[count][count2] = '0';
				mlx_put_image_to_window(window()->mlx_ptr, \
				window()->window_ptr, window()->img['0'], \
				count2 * 64, count * 64);
				movements(count, count2 +1);
				return ;
			}
		}
	}
}
