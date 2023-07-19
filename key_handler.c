/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:58:20 by matde-je          #+#    #+#             */
/*   Updated: 2023/07/19 20:02:20 by matde-je         ###   ########.fr       */
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
	{
		mlx_destroy_window(window()->mlx_ptr, window()->window_ptr);
		exit(0);
	}
	else if (key == UAK || key == WK)
		move_up(count, count2);
	else if (key == LAK || key == AK)
		move_left(count, count2);
	else if (key == RAK || key == DK)
		move_right(count, count2);
	else if (key == DAK || key == SK)
		move_down(count, count2);
	window_img();
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
				{
					mlx_destroy_window(window()->mlx_ptr, window()->window_ptr);
					exit(0);
				}
				map()->moves++;
				map()->matrix[count][count2] = '0';
				map()->matrix[count -1][count2] = 'P';
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
				{
					mlx_destroy_window(window()->mlx_ptr, window()->window_ptr);
					exit(0);
				}
				map()->moves++;
				ft_printf("%i", map()->moves);
				map()->matrix[count][count2] = '0';
				map()->matrix[count +1][count2] = 'P';
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
				{
					mlx_destroy_window(window()->mlx_ptr, window()->window_ptr);
					exit(0);
				}
				map()->moves++;
				map()->matrix[count][count2] = '0';
				map()->matrix[count][count2 -1] = 'P';
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
				{
					mlx_destroy_window(window()->mlx_ptr, window()->window_ptr);
					exit(0);
				}
				map()->moves++;
				map()->matrix[count][count2] = '0';
				map()->matrix[count][count2 +1] = 'P';
			}
		}
	}
}
