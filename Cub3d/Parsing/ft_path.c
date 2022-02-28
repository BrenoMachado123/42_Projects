/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <bmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:23:49 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/15 13:14:41 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	parse_direct(int a, int b)
{
	if (a == 'N' && b == 'O')
		return (1);
	else if (a == 'S' && b == 'O')
		return (1);
	else if (a == 'E' && b == 'A')
		return (1);
	else if (a == 'W' && b == 'E')
		return (1);
	return (0);
}

static void	check_path(char *line, t_data *data, int i, int end)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		data->no = ft_substr(line, i, end);
	else if (ft_strncmp(line, "SO", 2) == 0)
		data->so = ft_substr(line, i, end);
	else if (ft_strncmp(line, "WE", 2) == 0)
		data->we = ft_substr(line, i, end);
	else if (ft_strncmp(line, "EA", 2) == 0)
		data->ea = ft_substr(line, i, end);
	if (!path_error_handle(data, line))
		error_code(-1);
}

int	ft_parse_path(char *line)
{
	int	i;

	i = 0;
	if (is_empty_line(line))
		return (0);
	while (is_whitespace(line[i]))
		i++;
	if (!(parse_direct(line[i], line[i + 1])))
		return (0);
	i += 2;
	while (is_whitespace(line[i]))
		i++;
	while (ft_isprint(line[i]) && !(is_whitespace(line[i]) && line[i] != '\0'))
	{
		if (ft_isprint(line[i]) && is_whitespace(line[i + 1]))
			return (0);
		i++;
	}
	if (!(is_whitespace(line[i])) && line[i] != '\0')
		return (0);
	return (1);
}

int	ft_get_path(char *line, t_data *data)
{
	int	i;
	int	end;

	i = 0;
	end = 0;
	if (!ft_parse_path(line))
		error_code(-1);
	while (parse_direct(line[i], line[i + 1]))
		i += 2;
	while (is_whitespace(line[i]))
		i++;
	end = ft_strlen(line);
	check_path(line, data, i, end);
	return (1);
}

int	ft_get_cell_floor(t_data *data, char *line)
{
	int	i;
	int	j;

	i = 1;
	while (is_whitespace(line[i]))
		i++;
	j = i;
	while (ft_isprint(line[j]))
		j++;
	if (ft_strncmp(line, "F", 1) == 0)
		data->tex.floor_color = ft_substr(line, i, j);
	else if (ft_strncmp(line, "C", 1) == 0)
		data->tex.cell_color = ft_substr(line, i, j);
	data->count_fc++;
	if (ft_strncmp(line, "F", 1) == 0)
		return (check_floor_cell(data->tex.floor_color));
	else if (ft_strncmp(line, "C", 1) == 0)
		return (check_floor_cell(data->tex.cell_color));
	return (0);
}
