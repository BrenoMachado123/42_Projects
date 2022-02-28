/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <bmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 10:29:46 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/16 11:58:16 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_player(char p)
{
	if (p == 'N' || p == 'S' || p == 'W' || p == 'E')
		return (1);
	return (0);
}

int	get_player_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.map_y)
	{
		j = 0;
		while (data->map.matrix[i][j])
		{
			if (is_player(data->map.matrix[i][j]))
			{
				data->p.p_x = i + 0.5;
				data->p.p_y = j + 0.5;
				data->spawn = data->map.matrix[i][j];
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	set_spawn(t_data *player)
{
	player->p.rot_speed = 3.14;
	if (player->spawn == 'S')
		rot_left_right(player, -player->p.rot_speed);
	else if (player->spawn == 'E')
		rot_left_right(player, -player->p.rot_speed / 2);
	else if (player->spawn == 'W')
		rot_left_right(player, player->p.rot_speed / 2);
	player->p.rot_speed = ROTATION;
}
