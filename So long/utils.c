/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:11:51 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/23 16:59:05 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	valid_value(int v)
{
	if (v == '0'
		|| v == '1'
		|| v == 'C'
		|| v == 'E'
		|| v == 'P'
		|| v == 'S'
		|| v == 'B')
		return (1);
	return (0);
}

int	is_whitespace(int c)
{
	if (c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	is_empty_line(char *line)
{
	while (is_whitespace(*line))
		line++;
	if (*line == '\0')
		return (1);
	return (0);
}

int	is_map_border(t_data *data, int j, int i)
{
	if (i == 0 || j == 0 || i == data->map.mapy - 1
		|| j == data->map.mapx - 1)
		return (1);
	return (0);
}

int	wall_space(int e)
{
	if (e == ' ' || e == '1')
		return (1);
	return (0);
}
