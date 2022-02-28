/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:57:06 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/21 18:06:37 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

t_data	*get_data(t_data *data)
{
	static t_data	*data_result;

	if (data)
		data_result = data;
	return (data_result);
}

static void	free_array(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
	free(matrix);
}

void	free_elements(t_data *data)
{
	if (data->o_no >= 1)
		free(data->no);
	if (data->o_so >= 1)
		free(data->so);
	if (data->o_we >= 1)
		free(data->we);
	if (data->o_ea >= 1)
		free(data->ea);
	if (data->tex.floor_color)
		free(data->tex.floor_color);
	if (data->tex.cell_color)
		free(data->tex.cell_color);
	if (data->map.matrix)
		free_array(data->map.matrix);
	if (data->buffer)
		free(data->buffer);
	if (data->tbf)
		free(data->tbf);
	if (data->ray_buffer)
		free(data->ray_buffer);
}
