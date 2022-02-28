/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:50:13 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/23 17:16:21 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	select_draw(t_data *data, int p, int i, int j)
{
	if (p == '1')
		draw_2d(data, i, j, data->tbf[0]);
	else
		draw_2d(data, i, j, data->tbf[1]);
	if (p == 'P')
		draw_2d(data, i, j, data->tbf[2]);
	else if (p == 'C')
		draw_2d(data, i, j, data->tbf[5]);
	else if (p == 'E')
		draw_2d(data, i, j, data->tbf[7]);
	else if (p == 'S')
		draw_2d(data, i, j, data->tbf[12]);
	else if (p == 'B')
		draw_2d(data, i, j, data->tbf[18]);
}

void	draw_2d(t_data *data, int posy, int posx, void *object)
{
	posy *= 64;
	posx *= 64;
	mlx_put_image_to_window(data->img.addr, data->win, object, posx, posy);
}

void	draw_text(t_data *data)
{
	char	*str;

	str = ft_itoa(data->step_counter);
	mlx_string_put(data->mlx, data->win, 0, 0, -1, str);
	free(str);
}

void	draw_2d_wall(t_data *data)
{
	int	i;
	int	j;

	mlx_clear_window(data->mlx, data->win);
	i = -1;
	while (++i < data->map.mapy)
	{
		j = -1;
		while (++j < data->map.mapx)
			select_draw(data, data->map.matrix[i][j], i, j);
	}
	draw_text(data);
}
