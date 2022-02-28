/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_ai.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:11:44 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/23 18:15:32 by bmachado         ###   ########.fr       */
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
			if (data->map.matrix[i][j] == 'S')
			{
				data->e.px = i;
				data->e.py = j;
				return ;
			}
		}
	}
}

static void	behavior(t_data *data)
{
	if (data->p.px == data->e.px)
	{
		data->tbf[12] = data->tbf[13];
		data->e.wake = 1;
	}
	else
	{
		data->tbf[12] = data->m.s_enemy_sprite;
		data->e.wake = 0;
	}
}

static void	enemy_attack(t_data *d, int move)
{
	if (d->e.frames >= 200 && d->map.matrix[d->e.px][d->e.py + move] != '1')
	{
		d->map.matrix[d->e.px][d->e.py] = '0';
		if (move > 0)
			d->tbf[12] = d->tbf[17];
		else
			d->tbf[12] = d->tbf[16];
		d->map.matrix[d->e.px][d->e.py + move] = 'S';
	}
	if (d->map.matrix[d->e.px][d->e.py + move] == 'C'
		|| d->map.matrix[d->e.px][d->e.py + move] == 'B')
		return ;
	else if (d->map.matrix[d->e.px][d->e.py + move] == 'P')
		exit_code(LOST);
	if (d->e.frames >= 200)
		d->e.frames = 0;
	d->e.frames += 10;
}

void	special_enemy_ai(t_data *data)
{
	get_enemy_position(data);
	behavior(data);
	if (data->e.wake && data->e.py - data->p.py < 0)
		enemy_attack(data, 1);
	else if (data->e.wake && data->e.py - data->p.py > 0)
		enemy_attack(data, -1);
}
