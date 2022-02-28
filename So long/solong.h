/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:31:21 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/23 17:13:55 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53

# define TEX_H 64
# define TEX_W 64

# define WRONG_NUMBER_ARGS -1
# define NOT_BER_FILE -2
# define INVALID_MAP -3
# define INVALID_MAP_SHAPE -4
# define MALLOC_ERROR -5
# define INVALID_SETTING -6
# define LOAD_UNABLE -7
# define WIN 1
# define LOST 0
# define LEAVE 2

typedef struct s_map
{
	int		mapy;
	int		mapx;
	char	**matrix;
	void	*wall;
	void	*floor;
}				t_map;

typedef struct s_player
{
	int		px;
	int		py;
	int		count;
	void	*idle_sprite;
	int		frames;
	int		step_counter;
}				t_player;

typedef struct s_miscell
{
	void	*item_sprite;
	int		item_count;
	int		item_frames;
	void	*exit_sprite;
	int		exit_frames;
	int		exit_unlock;
	void	*s_enemy_sprite;
	void	*b_enemy_sprite;
	int		exit_count;
}				t_miscell;

typedef struct s_enemy
{
	int	px;
	int	py;
	int	frames;
	int	wake;
	int	dir;
}				t_enemy;

typedef struct s_bonusememy
{
	int	px;
	int	py;
	int	frames;
	int	dir;
}				t_bonusenemy;

typedef struct s_img
{
	int		*addr;
	void	*ptr;
	int		bpp;
	int		size_l;
	int		height;
	int		width;
	int		endian;
}				t_img;

typedef struct s_data
{
	char			*str_step;
	int				step_counter;
	void			*mlx;
	void			*win;
	int				width;
	int				height;
	int				*tbf[20];
	t_map			map;
	t_player		p;
	t_img			img;
	t_miscell		m;
	t_enemy			e;
	t_bonusenemy	b;
}				t_data;

void	exit_code(int type);
void	check_elements(t_data *data);
void	draw_2d_wall(t_data *data);
int		move_key(int k, t_data *d);
void	draw_2d(t_data *data, int posy, int posx, void *object);
void	get_textures(t_data *data);
void	idle_animation(t_data *data);
void	item_animation(t_data *data);
void	exit_animation(t_data *data);
void	check_collectable(t_data *data);
void	is_exit_unlocked(t_data *data, int px, int py);
void	special_enemy_ai(t_data *data);
t_data	init_data(void);
void	init_mlx(t_data *data);
void	clear_game(t_data *data);
void	normal_enemy_ai(t_data *data, int move);
void	n_enemy_animation(t_data *d);
void	print_steps(t_data *data);
void	draw_text(t_data *data);

int		create_map(t_data *data, char *map_name);
int		set_object_player(t_data *data, int posy, int posx);
int		valid_value(int v);
int		is_empty_line(char *line);
int		is_whitespace(int c);
int		is_map_border(t_data *data, int j, int i);
int		wall_space(int e);
int		**texture_buffer(int height, int width);
int		destroy_window(void);

t_data	*get_data(t_data *data);

#endif
