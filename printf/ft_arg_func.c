/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:35:50 by matde-je          #+#    #+#             */
/*   Updated: 2023/07/19 19:17:13 by matde-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	arg_check(char *s, int i)
{
	if (s[i] != '%' || (s[i] != '%' && s[i + 1] != 'i'))
		return (2);
	else
		return (0);
}

int	func(char *s, va_list	*arg, int i)
{
	if (s[i + 1] == 'i')
		return (ftint(arg));
	else
		return (0);
}
