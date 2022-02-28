/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <bmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 16:11:52 by bmachado          #+#    #+#             */
/*   Updated: 2021/11/03 12:58:51 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	key_init(t_data *data)
{
	data->k.a = 0;
	data->k.w = 0;
	data->k.s = 0;
	data->k.d = 0;
	data->k.left = 0;
	data->k.right = 0;
}

void	utils_init(t_data *data)
{	
	data->count_fc = 0;
	data->map.map_x = 0;
	data->map.map_y = 0;
	data->map.matrix = NULL;
	data->width = RES_WIDTH;
	data->height = RES_HEIGHT;
	data->o_no = 0;
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->tex.floor_color = NULL;
	data->tex.cell_color = NULL;
	data->o_so = 0;
	data->o_ea = 0;
	data->o_we = 0;
	data->have_map = 0;
	data->p.player_count = 0;
}

void	data_init(t_data *data)
{
	utils_init(data);
	data->mlx = mlx_init();
	data->img.ptr = mlx_new_image(data->mlx, data->width, data->height);
	data->img.addr = (int *)mlx_get_data_addr(data->img.ptr,
			&data->img.bpp, &data->img.size_line, &data->img.endian);
	data->buffer = create_buffer(data->height, data->width);
	data->tbf = create_buffer(4, TEX_H * TEX_WIDTH);
	data->ray_buffer = ft_calloc(data->width, sizeof(int));
	data->p.p_x = -1;
	data->p.p_y = -1;
	data->p.dir_x = -1.0;
	data->p.dir_y = 0.0;
	data->p.plane_x = 0.0;
	data->p.plane_y = 0.66;
	data->p.move_speed = 0.06;
	data->p.rot_speed = ROTATION;
}
