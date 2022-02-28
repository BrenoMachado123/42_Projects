/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 18:22:59 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/23 17:04:32 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_data	*get_data(t_data *data)
{
	static t_data	*data_result;

	if (data)
		data_result = data;
	return (data_result);
}

int	destroy_window(void)
{
	exit_code(LEAVE);
	return (1);
}

static void	free_map(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->map.mapy)
		free(data->map.matrix[i]);
	free(data->map.matrix);
}

void	clear_game(t_data *data)
{
	if (data->map.matrix)
		free_map(data);
}
