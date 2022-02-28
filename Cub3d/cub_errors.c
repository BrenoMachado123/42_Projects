/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:13:03 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/15 13:20:21 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	invalid_filename(char *filename)
{
	int		i;
	char	*end;
	int		is_invalid;

	i = 0;
	if (!filename)
		return (0);
	while (filename[i] != '.')
		i++;
	end = ft_substr(filename, i, ft_strlen(filename));
	if (!(ft_strncmp(end, ".cub", 4) == 0))
		is_invalid = 1;
	else
		is_invalid = 0;
	free(end);
	return (is_invalid);
}

int	path_error_handle(t_data *data, char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		data->o_no += 1;
	else if (ft_strncmp(line, "SO", 2) == 0)
		data->o_so += 1;
	else if (ft_strncmp(line, "WE", 2) == 0)
		data->o_we += 1;
	else if (ft_strncmp(line, "EA", 2) == 0)
		data->o_ea += 1;
	if (data->o_no > 1 || data->o_so > 1 || data->o_we > 1 || data->o_ea > 1)
		return (0);
	return (1);
}

void	error_code(int error)
{
	t_data	*data;

	data = get_data(NULL);
	if (error == -1)
		free_and_exit("Error\n ::Invalid .cub::\n", data);
	else if (error == -2)
		free_and_exit("Error\n ::Load texture was not possible::\n", data);
	else if (error == -3)
		free_and_exit("Error\n ::Invalid map format::\n", data);
	else if (error == -4)
		free_and_exit("Error\n ::File couldn't be opened::\n", data);
	else if (error == -5)
		free_and_exit("Error \n ::More than one player in the map::\n", data);
}

void	free_and_exit(char *msg, t_data *data)
{
	if (data)
		free_elements(data);
	ft_putstr_fd(msg, 1);
	exit(1);
}
