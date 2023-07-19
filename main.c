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
	if (!window()->window_ptr)
		free_all();
	mlx_loop(window()->mlx_ptr);
	return (0);
}

void	free_all(void)
{
	int	count;

	count = -1;
	while (++count < map()->size_y)
		free(map()->matrix[count]);
	free(map()->matrix);
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
