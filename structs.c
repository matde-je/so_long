/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:45:04 by matde-je          #+#    #+#             */
/*   Updated: 2023/07/12 19:00:49 by matde-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*map(void)
{
	static t_map	var;

	return (&var);
}

t_map	*map_path(void)
{
	static t_map	var;

	return (&var);
}

