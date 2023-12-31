/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:29:29 by matde-je          #+#    #+#             */
/*   Updated: 2023/09/27 14:03:37 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_window(void)
{
	window()->mlx_ptr = mlx_init();
	if (!window()->mlx_ptr)
		free_all(0);
	(window()->window_ptr) = mlx_new_window(window()->mlx_ptr, \
	map()->size_x * 64, map()->size_y * 64, "have fun");
	if (!window()->window_ptr)
		free_all(0);
	map()->moves = 0;
	img_func();
}

void	img_func(void)
{
	int	h;
	int	w;

	h = 64;
	w = 64;
	(window()->img['P']) = mlx_xpm_file_to_image(window()->mlx_ptr, \
	"xpm_files/porco.xpm", &w, &h);
	(window()->img['1']) = mlx_xpm_file_to_image(window()->mlx_ptr, \
	"xpm_files/arvore.xpm", &w, &h);
	(window()->img['0']) = mlx_xpm_file_to_image(window()->mlx_ptr, \
	"xpm_files/branco.xpm", &w, &h);
	(window()->img['C']) = mlx_xpm_file_to_image(window()->mlx_ptr, \
	"xpm_files/morango.xpm", &w, &h);
	(window()->img['E']) = mlx_xpm_file_to_image(window()->mlx_ptr, \
	"xpm_files/porta.xpm", &w, &h);
	window_img();
}

void	window_img(void)
{
	int	count;
	int	count2;
	int	pos;

	count = -1;
	while (++count < map()->size_y)
	{
		count2 = -1;
		while (++count2 < map()->size_x)
		{
			pos = map()->matrix[count][count2];
			if (window()->img[pos])
			{
				mlx_put_image_to_window(window()->mlx_ptr, \
				window()->window_ptr, window()->img[pos], \
				count2 * 64, count * 64);
			}
		}
	}
}

//key_handler helper functions
int	collectible(void)
{
	int	count;
	int	count2;

	count = -1;
	while (++count < map()->size_y)
	{
		count2 = -1;
		while (++count2 < map()->size_x)
		{
			if (map()->matrix[count][count2] == 'C')
				return (1);
		}
	}
	return (0);
}

void	movements(int count, int count2)
{
	map()->moves++;
	ft_printf("%i\n", map()->moves);
	map()->matrix[count][count2] = 'P';
	mlx_put_image_to_window(window()->mlx_ptr, \
	window()->window_ptr, window()->img['P'], \
	count2 * 64, count * 64);
}
