/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:22:15 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/23 16:58:49 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	valid_map_line(char *line)
{
	int	i;

	i = 0;
	if (is_empty_line(line))
		return (2);
	while (line[i])
	{
		if (!valid_value(line[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	get_mapy(char *map_name, t_data *data)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return ;
	while (gnl(fd, &line))
	{
		if (!is_empty_line(line) && valid_map_line(line))
			i++;
		else
			exit_code(INVALID_MAP);
	}
	free(line);
	close(fd);
	data->map.mapy = i;
}

static void	get_mapx(t_data *data)
{
	int	i;
	int	j;
	int	old;

	i = -1;
	old = 0;
	while (++i < data->map.mapy)
	{
		j = 0;
		while (data->map.matrix[i][j])
			j++;
		if (old != 0 && old != j)
			exit_code(INVALID_MAP_SHAPE);
		old = j;
	}
	data->map.mapx = j;
}

static void	check_map_walls(t_data *d)
{
	int	i;
	int	j;

	i = -1;
	while (++i < d->map.mapy)
	{
		j = -1;
		while (++j < d->map.mapx)
		{
			if (is_map_border(d, j, i) && !wall_space(d->map.matrix[i][j]))
				exit_code(INVALID_MAP);
			else if ((d->map.matrix[i][j] == '0'
				&& d->map.matrix[i][j + 1] == ' ')
			|| (d->map.matrix[i][j] == '0' && d->map.matrix[i][j - 1] == ' ')
			|| (d->map.matrix[i][j] == '0' && d->map.matrix[i + 1][j] == ' ')
			|| (d->map.matrix[i][j] == '0' && d->map.matrix[i - 1][j] == ' '))
				exit_code(INVALID_MAP);
		}
	}
}

int	create_map(t_data *data, char *map_name)
{
	char	*line;
	char	*tmp;
	int		fd;
	int		i;

	i = 0;
	get_mapy(map_name, data);
	data->map.matrix = (char **)malloc(sizeof(char *) * data->map.mapy);
	if (!data->map.matrix)
		exit_code(MALLOC_ERROR);
	fd = open(map_name, O_RDONLY);
	while (gnl(fd, &line))
	{
		tmp = (char *)malloc(sizeof(char) * ft_strlen(line) + 1);
		if (valid_map_line(line) == 1)
		{
			tmp = line;
			data->map.matrix[i++] = tmp;
		}
	}
	free(line);
	close(fd);
	get_mapx(data);
	check_map_walls(data);
	return (1);
}
