/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_issue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 16:47:15 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/15 13:30:48 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	fc_check(char *line)
{
	if (ft_strncmp(line, "F", 1) == 0
		|| ft_strncmp(line, "C", 1) == 0)
		return (1);
	else
		return (0);
}

static int	is_invalid_line(char *line, t_data *data)
{
	if (!check_mapline(line, data)
		&& !ft_parse_path(line)
		&& !fc_check(line)
		&& !is_empty_line(line))
		return (1);
	return (0);
}

static void	empty_counter(char *line, t_data *d, int map_isover)
{
	if (check_mapline(line, d))
	{
		d->cut++;
		d->is_map = 1;
	}
	else if (is_invalid_line(line, d))
		error_code(-1);
	else if (is_empty_line(line) && d->is_map == 1)
		d->emp++;
	if (d->cut == map_isover && !check_mapline(line, d))
		d->is_map = 0;
	if (d->is_map == 0 && is_empty_line(line))
		d->emp--;
}

int	parse_file(char *name, t_data *data)
{
	int		fd;
	char	*line;

	data->emp = 0;
	data->cut = 0;
	data->is_map = -1;
	fd = open(name, O_RDONLY);
	if (fd < 0)
		error_code(-4);
	while (gnl(fd, &line))
	{
		tabulation_handler(&line);
		empty_counter(line, data, data->map.map_y);
		if (data->is_map == 0 && !is_empty_line(line))
			error_code(-1);
	}
	if ((data->emp + data->map.map_y) > data->map.map_y)
		error_code(-1);
	close(fd);
	return (1);
}
