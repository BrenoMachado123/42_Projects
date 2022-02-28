/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <bmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 11:19:11 by bmachado          #+#    #+#             */
/*   Updated: 2021/10/27 13:38:19 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_raycasting(t_data *d, int x)
{
	d->r.camera_x = 2 * x / (double)d->width - 1;
	d->r.rdir_x = d->p.dir_x + d->p.plane_x * d->r.camera_x;
	d->r.rdir_y = d->p.dir_y + d->p.plane_y * d->r.camera_x;
	d->r.ray_x = (int)d->p.p_x;
	d->r.ray_y = (int)d->p.p_y;
	d->r.delta_distx = fabs(1 / d->r.rdir_x);
	d->r.delta_disty = fabs(1 / d->r.rdir_y);
}

void	side_dist(t_data *d)
{
	if (d->r.rdir_x < 0)
	{
		d->r.step_x = -1;
		d->r.side_distx = (d->p.p_x - d->r.ray_x) * d->r.delta_distx;
	}
	else
	{
		d->r.step_x = 1;
		d->r.side_distx = (d->r.ray_x + 1.0 - d->p.p_x) * d->r.delta_distx;
	}
	if (d->r.rdir_y < 0)
	{
		d->r.step_y = -1;
		d->r.side_disty = (d->p.p_y - d->r.ray_y) * d->r.delta_disty;
	}
	else
	{
		d->r.step_y = 1;
		d->r.side_disty = (d->r.ray_y + 1.0 - d->p.p_y) * d->r.delta_disty;
	}
}

void	ft_dda(t_data *d)
{
	double	x;
	double	y;

	while (d->map.matrix[d->r.ray_x][d->r.ray_y] != '1')
	{
		if (d->r.side_distx < d->r.side_disty)
		{
			d->r.side_distx += d->r.delta_distx;
			d->r.ray_x += d->r.step_x;
			d->r.side = 0;
		}
		else
		{
			d->r.side_disty += d->r.delta_disty;
			d->r.ray_y += d->r.step_y;
			d->r.side = 1;
		}
	}
	x = d->r.ray_x - d->p.p_x + (1 - d->r.step_x) / 2;
	y = d->r.ray_y - d->p.p_y + (1 - d->r.step_y) / 2;
	if (d->r.side == 0)
		d->r.perpwall_dist = x / d->r.rdir_x;
	else
		d->r.perpwall_dist = y / d->r.rdir_y;
}

void	line_height(t_data *d)
{
	double	calc;

	calc = d->height / d->r.perpwall_dist;
	d->tex.line_h = (int)calc;
	d->tex.draw_start = (-d->tex.line_h / 2) + (d->height / 2);
	if (d->tex.draw_start < 0)
		d->tex.draw_start = 0;
	d->tex.draw_end = (d->tex.line_h / 2) + (d->height / 2);
	if (d->tex.draw_end >= d->height)
		d->tex.draw_end = d->height - 1;
}

void	coloring(t_data *d)
{
	if (d->r.side == 0 && d->r.rdir_x > 0)
		d->tex.tx_n = 1;
	else if (d->r.side == 0 && d->r.rdir_x <= 0)
		d->tex.tx_n = 0;
	if (d->r.rdir_y > 0 && d->r.side == 1)
		d->tex.tx_n = 2;
	else if (d->r.rdir_y <= 0 && d->r.side == 1)
		d->tex.tx_n = 3;
}
