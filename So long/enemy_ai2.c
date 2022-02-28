/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_ai2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:14:40 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/22 16:10:29 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	get_enemy_position(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map.mapy)
	{
		j = -1;
		while (++j < data->map.mapx)
		{
			if (data->map.matrix[i][j] == 'B')
			{
				data->b.px = i;
				data->b.py = j;
				return ;
			}
		}
	}
}

static void	enemy_attack_sides(t_data *d, int move)
{
	if (d->map.matrix[d->b.px][d->b.py + move] == '1')
		move *= -1;
	if (d->map.matrix[d->b.px][d->b.py + move] == '0')
	{
		d->map.matrix[d->b.px][d->b.py] = '0';
		d->map.matrix[d->b.px][d->b.py + move] = 'B';
	}
	if (d->map.matrix[d->b.px][d->b.py + move] == 'C')
		return ;
	else if (d->map.matrix[d->b.px][d->b.py + move] == 'P')
		exit_code(LOST);
}

static void	enemy_attack_updown(t_data *d, int move)
{
	if (d->map.matrix[d->b.px + move][d->b.py] == '1')
		move *= -1;
	if (d->map.matrix[d->b.px + move][d->b.py] == '0')
	{
		d->map.matrix[d->b.px][d->b.py] = '0';
		d->map.matrix[d->b.px + move][d->b.py] = 'B';
	}
	if (d->map.matrix[d->b.px + move][d->b.py] == 'C')
		return ;
	else if (d->map.matrix[d->b.px + move][d->b.py] == 'P')
		exit_code(LOST);
}

void	normal_enemy_ai(t_data *data, int move)
{
	move *= -1;
	get_enemy_position(data);
	if (data->b.dir == 0)
		enemy_attack_sides(data, move);
	else
		enemy_attack_updown(data, move);
}
