/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <bmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 17:36:32 by bmachado          #+#    #+#             */
/*   Updated: 2021/11/03 12:59:39 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	**create_buffer(int height, int width)
{
	int	**buffer;
	int	i;

	buffer = (int **)malloc(sizeof(int *) * height);
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < height)
	{
		buffer[i] = (int *)malloc(sizeof(int) * width);
		if (!buffer[i])
			return (NULL);
		i++;
	}
	return (buffer);
}

void	draw_buffer(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
			data->img.addr[y * data->width + x] = data->buffer[y][x];
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
}

int	press_key(int k, t_data *data)
{
	if (k == A)
		data->k.a = 1;
	else if (k == S)
		data->k.s = 1;
	else if (k == D)
		data->k.d = 1;
	else if (k == W)
		data->k.w = 1;
	else if (k == LEFT_ARROW)
		data->k.left = 1;
	else if (k == RIGHT_ARROW)
		data->k.right = 1;
	else if (k == ESC)
	{
		free_and_exit(NULL, data);
		exit(0);
	}
	return (0);
}

int	release_key(int k, t_data *data)
{
	if (k == A)
		data->k.a = 0;
	else if (k == S)
		data->k.s = 0;
	else if (k == D)
		data->k.d = 0;
	else if (k == W)
		data->k.w = 0;
	else if (k == LEFT_ARROW)
		data->k.left = 0;
	else if (k == RIGHT_ARROW)
		data->k.right = 0;
	return (0);
}
