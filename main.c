/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:44:48 by matde-je          #+#    #+#             */
/*   Updated: 2023/07/12 11:23:55 by matde-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int	count;

	count = -1;
    if (argc != 2)
        error("Invalid args");
    check_map(argv[1]);
	while (++count < map()->size_x)
	{
		free(map()->matrix[count]);
	}
	free(map()->matrix);
}
