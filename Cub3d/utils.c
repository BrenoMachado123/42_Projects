/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <bmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 15:28:19 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/28 13:14:28 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	error_txt(char *txt)
{
	ft_putstr_fd(txt, 1);
	exit(1);
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
	if (i == 0 || j == 0 || i == data->map.map_y - 1
		|| j == data->map.map_x - 1)
		return (1);
	return (0);
}

int	wall_space(char e)
{
	if (e == ' ' || e == '1')
		return (1);
	return (0);
}
