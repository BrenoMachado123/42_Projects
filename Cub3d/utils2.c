/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <bmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:53:03 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/23 16:53:30 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	len_x(t_data *data, int n)
{
	int		c;
	char	**tmp;

	c = 0;
	tmp = data->map.matrix;
	while (tmp[n][c])
		c++;
	return (c);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_get_color(char *str)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(str);
	g = ft_atoi(ft_strchr(str, ',') + 1);
	b = ft_atoi(ft_strrchr(str, ',') + 1);
	return (create_trgb(0, r, g, b));
}

void	tabulation_handler(char **line)
{
	int		i;
	char	*str;
	char	*temp;

	i = 0;
	while (ft_strchr(*line, '\t'))
	{
		i = -1;
		while ((*line)[++i])
		{
			if ((*line)[i] == '\t')
			{
				temp = ft_substr(*line, 0, i);
				str = ft_strjoin(temp, "    ");
				free(temp);
				temp = ft_strjoin(str, &(*line)[i + 1]);
				free(*line);
				free(str);
				*line = temp;
			}
		}
	}
}

int	check_mapline(char *line, t_data *data)
{
	int	i;
	int	sucess;

	i = 0;
	sucess = 0;
	if (is_empty_line(line) && data->have_map == 1)
		return (0);
	while (line[i])
	{
		if (valid_value(line[i]) || is_whitespace(line[i]))
			sucess = 1;
		else
			return (0);
		i++;
	}
	return (sucess);
}
