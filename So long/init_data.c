/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 10:48:12 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/23 17:14:13 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	load_texture(t_data *data, char *path, int i);

t_data	init_data(void)
{
	t_data	data;

	data.map.mapy = 0;
	data.map.mapx = 0;
	data.map.matrix = NULL;
	data.p.count = 0;
	data.p.px = -1;
	data.p.py = -1;
	data.step_counter = 0;
	data.p.frames = 0;
	data.m.item_frames = 0;
	data.m.item_count = 0;
	data.m.exit_frames = 0;
	data.m.exit_unlock = 0;
	data.e.frames = 0;
	data.b.frames = 0;
	data.b.dir = 0;
	data.m.exit_count = 0;
	return (data);
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->img.ptr = mlx_new_image(data->mlx, data->map.mapx * TEX_W,
			data->map.mapy * TEX_H);
	data->img.addr = (int *)mlx_get_data_addr(data->img.ptr,
			&data->img.bpp, &data->img.size_l, &data->img.endian);
	data->win = mlx_new_window(data->mlx, data->map.mapx * TEX_W,
			data->map.mapy * TEX_H, "So_long");
}

void	get_textures(t_data *data)
{
	load_texture(data, "./textures/wall.xpm", 0);
	load_texture(data, "./textures/floor.xpm", 1);
	load_texture(data, "./textures/slime.xpm", 2);
	load_texture(data, "./textures/slime_2.xpm", 3);
	load_texture(data, "./textures/slime_3.xpm", 4);
	load_texture(data, "./textures/item.xpm", 5);
	load_texture(data, "./textures/item_2.xpm", 6);
	load_texture(data, "./textures/Exit_off.xpm", 7);
	load_texture(data, "./textures/Exit_off_2.xpm", 8);
	load_texture(data, "./textures/Exit_activate.xpm", 9);
	load_texture(data, "./textures/Exit_on.xpm", 10);
	load_texture(data, "./textures/Exit_on_2.xpm", 11);
	load_texture(data, "./textures/s_enemy_sleep.xpm", 12);
	load_texture(data, "./textures/s_enemy_awake.xpm", 13);
	load_texture(data, "./textures/s_enemy_a2.xpm", 14);
	load_texture(data, "./textures/s_enemy_a3.xpm", 15);
	load_texture(data, "./textures/s_enemy_attl.xpm", 16);
	load_texture(data, "./textures/s_enemy_attr.xpm", 17);
	load_texture(data, "./textures/normal_enemy.xpm", 18);
	load_texture(data, "./textures/normal_enemy2.xpm", 19);
	data->p.idle_sprite = data->tbf[2];
	data->m.item_sprite = data->tbf[5];
	data->m.exit_sprite = data->tbf[7];
	data->m.s_enemy_sprite = data->tbf[12];
	data->m.b_enemy_sprite = data->tbf[18];
}

static void	load_texture(t_data *data, char *path, int i)
{
	data->tbf[i] = mlx_xpm_file_to_image(data->mlx, path,
			&data->img.width, &data->img.height);
	if (!data->tbf[i])
		exit(1);
}
