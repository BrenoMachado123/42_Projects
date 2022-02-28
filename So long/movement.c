/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:44:17 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/27 14:48:15 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	move_front_back(t_data *d, int move)
{
	int	px;
	int	py;

	px = d->p.px;
	py = d->p.py;
	if (d->map.matrix[px + move][py] == '0')
	{		
		d->map.matrix[px][py] = '0';
		d->map.matrix[px + move][py] = 'P';
		d->p.px += move;
		d->step_counter++;
		print_steps(d);
	}
	if (d->map.matrix[px + move][py] == 'C')
	{
		d->map.matrix[px + move][py] = '0';
		d->map.matrix[px][py] = '0';
		d->map.matrix[px + move][py] = 'P';
		d->p.px += move;
		d->m.item_count--;
	}
	is_exit_unlocked(d, (px + move), py);
	d->b.dir = 1;
	normal_enemy_ai(d, move);
}

static void	move_left_right(t_data *d, int move)
{
	int	px;
	int	py;

	px = d->p.px;
	py = d->p.py;
	if (d->map.matrix[px][py + move] == '0')
	{	
		d->map.matrix[px][py] = '0';
		d->map.matrix[px][py + move] = 'P';
		d->p.py += move;
		d->step_counter++;
		print_steps(d);
	}
	if (d->map.matrix[px][py + move] == 'C')
	{
		d->map.matrix[px][py + move] = '0';
		d->map.matrix[px][py] = '0';
		d->map.matrix[px][py + move] = 'P';
		d->p.py += move;
		d->m.item_count--;
	}
	is_exit_unlocked(d, px, (py + move));
	d->b.dir = 0;
	normal_enemy_ai(d, move);
}

int	move_key(int k, t_data *d)
{
	if (k == W)
		move_front_back(d, -1);
	if (k == S)
		move_front_back(d, 1);
	if (k == D)
		move_left_right(d, 1);
	if (k == A)
		move_left_right(d, -1);
	if (k == ESC)
		exit_code(LEAVE);
	return (0);
}
