/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:44:48 by matde-je          #+#    #+#             */
/*   Updated: 2023/07/19 19:38:28 by matde-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		error("Error in number of arguments");
	check_map(argv[1]);
	new_window();
	mlx_key_hook(window()->window_ptr, key_handler, NULL);
	mlx_hook(window()->window_ptr, 17, 131072, &free_all, NULL);
	if (!window()->window_ptr)
		free_all();
	else
		mlx_loop(window()->mlx_ptr);
	return (0);
}

int	free_all(void)
{
	int	count;

	count = -1;
	while (++count < map()->size_y)
		free(map()->matrix[count]);
	free(map()->matrix);
	if (window()->img['P'])
		mlx_destroy_image(window()->mlx_ptr, window()->img['P']);
	if (window()->img['0'])
		mlx_destroy_image(window()->mlx_ptr, window()->img['0']);
	if (window()->img['1'])
		mlx_destroy_image(window()->mlx_ptr, window()->img['1']);
	if (window()->img['E'])
		mlx_destroy_image(window()->mlx_ptr, window()->img['E']);
	if (window()->img['C'])
		mlx_destroy_image(window()->mlx_ptr, window()->img['C']);
	if (window()->window_ptr)
		mlx_destroy_window(window()->mlx_ptr, window()->window_ptr);
	if (window()->mlx_ptr)
	{
		mlx_destroy_display(window()->mlx_ptr);
		free(window()->mlx_ptr);
	}
	exit(0);
	return (0);
}

t_map	*map(void)
{
	static t_map	var;

	return (&var);
}

t_window	*window(void)
{
	static t_window		var;

	return (&var);
}
