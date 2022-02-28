/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:11:45 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/22 16:02:10 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	idle_animation(t_data *d)
{
	void	*idle_one;
	void	*idle_two;

	idle_one = d->tbf[3];
	idle_two = d->tbf[4];
	if (d->p.frames == 200)
		d->tbf[2] = d->p.idle_sprite;
	else if (d->p.frames == 300)
		d->tbf[2] = idle_one;
	else if (d->p.frames == 500)
		d->tbf[2] = idle_two;
	if (d->p.frames == 500)
		d->p.frames = 0;
	d->p.frames += 10;
}

void	item_animation(t_data *d)
{
	void	*item_one;

	item_one = d->tbf[6];
	if (d->m.item_frames == 200)
		d->tbf[5] = d->m.item_sprite;
	else if (d->m.item_frames == 300)
		d->tbf[5] = item_one;
	if (d->m.item_frames == 300)
		d->m.item_frames = 0;
	d->m.item_frames += 10;
}

void	n_enemy_animation(t_data *d)
{
	void	*enemy_one;

	enemy_one = d->tbf[19];
	if (d->b.frames <= 600)
		d->tbf[18] = d->m.b_enemy_sprite;
	else
		d->tbf[18] = enemy_one;
	if (d->b.frames == 1200)
		d->b.frames = 0;
	d->b.frames += 10;
}

void	exit_animation(t_data *d)
{
	void	*exit_one;

	exit_one = d->tbf[8];
	if (d->m.exit_frames == 300)
		d->tbf[7] = d->m.exit_sprite;
	else if (d->m.exit_frames == 900)
		d->tbf[7] = exit_one;
	if (d->m.exit_frames == 900)
		d->m.exit_frames = 0;
	d->m.exit_frames += 5;
}
