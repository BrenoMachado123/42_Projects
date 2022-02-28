/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:54:14 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/27 14:47:29 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	is_ber_file(char *map_file)
{
	static char	*tmp;
	int			i;
	int			v;

	i = 0;
	v = 0;
	if (!map_file)
		return (v);
	while (map_file[i] != '.')
		i++;
	tmp = ft_substr(map_file, i, ft_strlen(map_file));
	if (ft_strncmp(tmp, ".ber", 4) == 0)
		v = 1;
	free(tmp);
	return (v);
}

static void	check_args(int argc, char **argv)
{
	if (argc != 2)
		exit_code(WRONG_NUMBER_ARGS);
	else if (!is_ber_file(argv[1]))
		exit_code(NOT_BER_FILE);
}

static int	main_loop(t_data *data)
{
	draw_2d_wall(data);
	idle_animation(data);
	exit_animation(data);
	item_animation(data);
	special_enemy_ai(data);
	n_enemy_animation(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	check_args(argc, argv);
	data = init_data();
	create_map(&data, argv[1]);
	check_elements(&data);
	init_mlx(&data);
	get_textures(&data);
	mlx_hook(data.win, 2, 0, &move_key, &data);
	mlx_hook(data.win, 17, 0, &destroy_window, &data);
	mlx_loop_hook(data.mlx, &main_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
