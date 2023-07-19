/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 21:30:21 by matde-je          #+#    #+#             */
/*   Updated: 2023/07/19 19:15:52 by matde-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

long int	ft_putnbr(long int n)
{
	int		count;
	char	print;

	count = 0;
	if (n >= 10)
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	else
	{
		print = '0' + n;
		write(1, &print, 1);
		count++;
	}
	return (count);
}
