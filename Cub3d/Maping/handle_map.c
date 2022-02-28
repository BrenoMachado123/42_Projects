/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <bmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:42:48 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/15 13:13:46 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	valid_value(char v)
{
	if (v == '0'
		|| v == '1'
		|| v == 'N'
		|| v == 'E'
		|| v == 'S'
		|| v == 'W'
		|| v == ' ')
		return (1);
	else
		return (0);
}

char	*ft_partmap(char *line, int i)
{
	char	*part;
	int		j;

	part = (char *)malloc(sizeof(char) * ft_strlen(line) + 1);
	if (!part)
		return (NULL);
	j = 0;
	while (line[i] != '\0')
	{
		if (valid_value(line[i]))
			part[j++] = line[i];
		else
		{
			free(part);
			return (NULL);
		}
		i++;
	}
	part[j] = '\0';
	return (part);
}

int	ft_map(t_data *data, char *line, int i)
{
	char	**tmp;
	int		j;

	tmp = malloc(sizeof(char *) * (data->map.map_y + 2));
	if (!tmp)
		return (0);
	j = -1;
	while (++j < data->map.map_y)
		tmp[j] = data->map.matrix[j];
	tmp[data->map.map_y] = ft_partmap(line, i);
	if (!tmp[data->map.map_y])
	{
		free(tmp);
		return (0);
	}
	tmp[data->map.map_y + 1] = NULL;
	if (data->map.map_y > 0)
		free(data->map.matrix);
	data->map.matrix = tmp;
	data->map.map_y++;
	return (1);
}

int	parse_full_map(t_data *d)
{
	int		i;
	int		j;

	i = -1;
	while (++i < d->map.map_y)
	{
		j = -1;
		d->map.map_x = len_x(d, i);
		while (++j < d->map.map_x)
		{
			if (is_map_border(d, j, i) && !wall_space(d->map.matrix[i][j]))
				error_code(-3);
			else if ((d->map.matrix[i][j] == '0'
				&& d->map.matrix[i][j + 1] == ' ')
			|| (d->map.matrix[i][j] == '0' && d->map.matrix[i][j - 1] == ' ')
			|| (d->map.matrix[i][j] == '0' && d->map.matrix[i + 1][j] == ' ')
			|| (d->map.matrix[i][j] == '0' && d->map.matrix[i - 1][j] == ' '))
				error_code(-3);
			if (is_player(d->map.matrix[i][j]))
				d->p.player_count += 1;
		}
	}
	if (d->p.player_count > 1)
		error_code(-5);
	return (1);
}
