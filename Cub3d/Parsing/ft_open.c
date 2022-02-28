/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <bmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:44:09 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/15 13:15:05 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	is_something_empty(t_data *data)
{
	if (!data->no
		|| !data->so
		|| !data->ea
		|| !data->we
		|| !data->tex.cell_color
		|| !data->tex.floor_color)
		return (1);
	return (0);
}

static void	get_map(t_data *data, char *line)
{
	if (check_mapline(line, data) && is_something_empty(data))
		error_code(-1);
	if (!is_something_empty(data) && check_mapline(line, data))
	{
		tabulation_handler(&line);
		ft_map(data, line, 0);
	}
}

static void	parse_file_one(t_data *data)
{
	if (!check_floor_cell(data->tex.floor_color)
		|| !check_floor_cell(data->tex.cell_color))
		error_code(-1);
	if (data->count_fc > 2)
		error_code(-1);
	if (!parse_full_map(data))
		error_code(-3);
	if (!get_player_pos(data))
		error_code(-3);
	data->tex.r_floor_color = ft_get_color(data->tex.floor_color);
	data->tex.r_cell_color = ft_get_color(data->tex.cell_color);
}

int	get_elements_from_file(char *map_name, t_data *d)
{
	int		fd;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		error_code(-4);
	while (gnl(fd, &line))
	{
		if (ft_parse_path(line))
			ft_get_path(line, d);
		else if (fc_check(line))
			ft_get_cell_floor(d, line);
		get_map(d, line);
	}
	parse_file_one(d);
	close(fd);
	parse_file(map_name, d);
	return (1);
}
