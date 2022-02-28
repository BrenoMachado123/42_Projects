/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:48:52 by bmachado          #+#    #+#             */
/*   Updated: 2021/11/03 13:00:37 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	increase_texture(t_data *d, int x)
{
	int	y;

	y = 0;
	while (y < d->tex.draw_start)
	{
		d->buffer[y][x] = d->tex.r_cell_color;
		y++;
	}
	while (y < d->tex.draw_end)
	{
		d->tex.tx_y = (int)d->tex.p_tex & (TEX_H - 1);
		d->tex.p_tex += d->r.step;
		d->tex.color = d->tbf[d->tex.tx_n][TEX_H * d->tex.tx_y + d->tex.tx_x];
		d->buffer[y][x] = d->tex.color;
		y++;
	}
	while (y < d->height)
	{
		d->buffer[y][x] = d->tex.r_floor_color;
		y++;
	}
}

void	cast_texture(t_data *d)
{
	if (d->r.side == 0)
		d->r.wall_x = d->p.p_y + d->r.perpwall_dist * d->r.rdir_y;
	else
		d->r.wall_x = d->p.p_x + d->r.perpwall_dist * d->r.rdir_x;
	d->r.wall_x -= floor(d->r.wall_x);
	d->tex.tx_x = (int)(d->r.wall_x * (double)TEX_WIDTH);
	if (d->r.side == 0 && d->r.rdir_x > 0)
		d->tex.tx_x = TEX_WIDTH - d->tex.tx_x - 1;
	if (d->r.side == 1 && d->r.rdir_y < 0)
		d->tex.tx_x = TEX_WIDTH - d->tex.tx_x - 1;
	d->r.step = 1.0 * TEX_H / d->tex.line_h;
	d->tex.p_tex = (d->tex.draw_start - d->height / 2 + d->tex.line_h / 2);
	d->tex.p_tex *= d->r.step;
	if (d->tex.draw_start > d->height || d->tex.draw_start < 0)
		d->tex.draw_start = d->height;
	if (d->tex.draw_end > d->height || d->tex.draw_end < 0)
		d->tex.draw_end = d->height;
}
