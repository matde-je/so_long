/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:48:00 by matde-je          #+#    #+#             */
/*   Updated: 2022/12/15 23:20:37 by matde-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n' )
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *linha, char *buffer)
{
	char	*final;
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
	final = malloc(ft_strlen(linha) + ft_strlen(buffer) + 1);
	if (!final)
		return (0);
	while (linha != NULL && linha[i] != '\0')
	{
		final[i] = linha[i];
		i++;
	}
	while (buffer != NULL && buffer[j] != '\0')
	{
		final[i++] = buffer[j];
		if (buffer[j] == '\n')
			break ;
		j++;
	}
	final[i] = '\0';
	free(linha);
	return (final);
}
