/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:49:53 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/23 18:18:25 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	print_steps(t_data *data)
{
	ft_putstr_fd("Step >> ", 1);
	ft_putnbr_fd(data->step_counter, 1);
	ft_putchar_fd('\n', 1);
}

void	check_elements(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.mapy)
	{
		j = 0;
		while (data->map.matrix[i][j])
		{
			if (data->map.matrix[i][j] == 'P')
			{
				data->p.px = i;
				data->p.py = j;
				data->p.count += 1;
			}
			if (data->map.matrix[i][j] == 'C')
				data->m.item_count += 1;
			j++;
		}
		i++;
	}
	if (data->p.count != 1 || data->m.item_count < 1)
		exit_code(INVALID_SETTING);
}

void	is_exit_unlocked(t_data *data, int px, int py)
{
	if (data->m.item_count == 0 && data->m.exit_unlock == 0)
	{
		data->tbf[7] = data->tbf[9];
		data->m.exit_sprite = data->tbf[10];
		data->tbf[8] = data->tbf[11];
		data->m.exit_unlock = 1;
	}
	if (data->map.matrix[px][py] == 'E' && data->m.item_count == 0)
	{
		data->map.matrix[data->p.px][data->p.py] = '0';
		data->map.matrix[px][py] = 'P';
		exit_code(WIN);
	}
}
