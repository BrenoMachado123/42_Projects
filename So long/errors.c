/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:49:50 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/23 17:02:19 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	leave(char *exit_msg)
{
	t_data	*data;

	data = get_data(NULL);
	if (data)
		clear_game(data);
	ft_putendl_fd(exit_msg, 1);
	exit(1);
}

void	exit_code(int type)
{
	if (type == WRONG_NUMBER_ARGS)
		leave("::Error::\n<Invalid number of args>");
	else if (type == NOT_BER_FILE)
		leave("::Error::\n<Only .ber files allowed>");
	else if (type == INVALID_MAP)
		leave("::Error::\n<Invalid map>");
	else if (type == INVALID_MAP_SHAPE)
		leave("::Error::\n<Map must be a retangule>");
	else if (type == MALLOC_ERROR)
		leave("::Error::\n<Memory allocation problem>");
	else if (type == INVALID_SETTING)
		leave("::Error::\n<Map setting invalid>");
	else if (type == LOAD_UNABLE)
		leave("::Error::\n<Load textures not possible>");
	else if (type == WIN)
		leave("YOU WON!");
	else if (type == LOST)
		leave("YOU LOST!");
	else if (type == LEAVE)
		leave(NULL);
}
