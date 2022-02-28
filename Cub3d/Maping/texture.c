/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <bmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:52:14 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/17 15:56:22 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_floor_cell(char *line)
{
	int	num;
	int	counter;

	num = 0;
	counter = 0;
	while (*line)
	{
		if ((ft_isdigit(*line) || *line == ',') && counter <= 2)
		{
			if (ft_isdigit(*line) && ft_atoi(line) > 255)
				return (0);
			else if (*line == ',')
			{
				if (!ft_isdigit(*(line + 1)))
					return (0);
				counter++;
			}
			line++;
		}
		else
			return (0);
	}
	return (1);
}

int	load_image(t_data *data, int *tex, char *path, t_img *img)
{
	int	y;
	int	x;

	img->ptr = mlx_xpm_file_to_image(data->mlx, path,
			&img->width, &img->height);
	if (!img->ptr)
		return (0);
	img->addr = (int *)mlx_get_data_addr(img->ptr, &img->bpp,
			&img->size_line, &img->endian);
	y = 0;
	while (y < img->width)
	{
		x = 0;
		while (x < img->height)
		{
			tex[(img->width * y) + x] = img->addr[(img->width * y) + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, img->ptr);
	return (1);
}

int	load_textures(t_data *data)
{
	t_img	img;

	if (!load_image(data, data->tbf[0], data->no, &img))
		return (0);
	if (!load_image(data, data->tbf[1], data->so, &img))
		return (0);
	if (!load_image(data, data->tbf[2], data->ea, &img))
		return (0);
	if (!load_image(data, data->tbf[3], data->we, &img))
		return (0);
	return (1);
}
