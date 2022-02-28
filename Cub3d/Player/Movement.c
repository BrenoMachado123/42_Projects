/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <bmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 15:08:01 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/21 17:58:17 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	m_front_back(t_data *d, double movespeed)
{
	double	mapx;
	double	mapy;
	double	cx;
	double	cy;

	cx = d->p.p_x;
	cy = d->p.p_y;
	mapx = d->p.p_x + d->p.dir_x * movespeed;
	mapy = d->p.p_y + d->p.dir_y * movespeed;
	if (d->map.matrix[(int)mapx][(int)cy] != '1')
		d->p.p_x = mapx;
	if (d->map.matrix[(int)cx][(int)mapy] != '1')
		d->p.p_y = mapy;
}

void	m_left_right(t_data *d, double movespeed)
{
	double	mapx;
	double	mapy;
	double	cx;
	double	cy;

	cx = d->p.p_x;
	cy = d->p.p_y;
	mapx = d->p.p_x + d->p.dir_y * movespeed;
	mapy = d->p.p_y - d->p.dir_x * movespeed;
	if (d->map.matrix[(int)mapx][(int)cy] != '1')
		d->p.p_x = mapx;
	if (d->map.matrix[(int)cx][(int)mapy] != '1')
		d->p.p_y = mapy;
}

void	rot_left_right(t_data *d, double rotspeed)
{
	d->p.old_dirx = d->p.dir_x;
	d->p.dir_x *= cos(rotspeed);
	d->p.dir_x -= d->p.dir_y * sin(rotspeed);
	d->p.dir_y *= cos(rotspeed);
	d->p.dir_y += d->p.old_dirx * sin(rotspeed);
	d->p.old_planex = d->p.plane_x;
	d->p.plane_x *= cos(rotspeed);
	d->p.plane_x -= d->p.plane_y * sin(rotspeed);
	d->p.plane_y *= cos(rotspeed);
	d->p.plane_y += d->p.old_planex * sin(rotspeed);
}

void	move_key(t_data *d)
{
	if (d->k.w)
		m_front_back(d, d->p.move_speed);
	if (d->k.s)
		m_front_back(d, -d->p.move_speed);
	if (d->k.d)
		m_left_right(d, d->p.move_speed);
	if (d->k.a)
		m_left_right(d, -d->p.move_speed);
	if (d->k.left)
		rot_left_right(d, d->p.rot_speed);
	if (d->k.right)
		rot_left_right(d, -d->p.rot_speed);
}
