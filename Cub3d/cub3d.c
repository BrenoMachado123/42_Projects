/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:22:13 by bmachado          #+#    #+#             */
/*   Updated: 2021/11/03 13:00:11 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static int	destroy_window(t_data *data)
{
	free_and_exit(NULL, data);
	exit(0);
}

void	update_data(t_data *data)
{
	int	x;

	x = -1;
	while (++x < data->width)
	{
		init_raycasting(data, x);
		side_dist(data);
		ft_dda(data);
		line_height(data);
		coloring(data);
		cast_texture(data);
		increase_texture(data, x);
		data->ray_buffer[x] = data->r.perpwall_dist;
	}
}

int	main_loop(t_data *mlx)
{
	move_key(mlx);
	update_data(mlx);
	draw_buffer(mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 2 || argc == 1 || invalid_filename(argv[1]))
		error_txt("Error\n ::Invalid Arguments format::\n");
	key_init(&data);
	data_init(&data);
	get_elements_from_file(argv[1], &data);
	if (!load_textures(&data))
		error_code(-2);
	set_spawn(&data);
	data.win = mlx_new_window(data.mlx, data.width, data.height, "cub3d");
	mlx_hook(data.win, 2, 0, &press_key, &data);
	mlx_hook(data.win, 3, 0, &release_key, &data);
	mlx_hook(data.win, 17, 0, &destroy_window, &data);
	mlx_loop_hook(data.mlx, &main_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
