/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <bmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:29:18 by bmachado          #+#    #+#             */
/*   Updated: 2021/09/16 18:41:56 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"

# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53
# define LEFT_ARROW	123
# define RIGHT_ARROW 124
# define RES_HEIGHT 1080
# define RES_WIDTH	1920
# define TEX_H 64
# define TEX_WIDTH 64
# define ROTATION 0.03

typedef struct s_keys
{
	int	a;
	int	w;
	int	s;
	int	d;
	int	left;
	int	right;
}				t_keys;

typedef struct s_img
{
	int		*addr;
	void	*ptr;
	int		bpp;
	int		size_line;
	int		endian;
	int		height;
	int		width;
	char	*t;
}				t_img;

typedef struct s_map
{
	int		map_x;
	int		map_y;
	char	**matrix;
}				t_map;

typedef struct s_player
{
	double	p_x;
	double	p_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	old_dirx;
	double	old_diry;
	double	old_planex;
	double	old_planey;
	double	move_speed;
	double	rot_speed;
	int		player_count;
}				t_player;

typedef struct s_ray
{
	double	camera_x;
	double	rdir_x;
	double	rdir_y;
	double	delta_distx;
	double	delta_disty;
	double	side_distx;
	double	side_disty;
	double	perpwall_dist;
	double	step;
	double	wall_x;
	int		ray_x;
	int		ray_y;
	int		step_x;
	int		step_y;
	int		side;
}				t_ray;

typedef struct s_tex
{
	double	p_tex;
	int		tx_x;
	int		tx_y;
	int		tx_n;
	int		color;
	int		draw_start;
	int		draw_end;
	int		line_h;
	int		r_cell_color;
	int		r_floor_color;
	char	*cell_color;
	char	*floor_color;
}				t_tex;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			**buffer;
	t_img		img;
	t_keys		k;
	t_map		map;
	t_player	p;
	t_ray		r;
	t_tex		tex;
	int			width;
	int			height;
	int			spawn;
	int			count_fc;
	int			trigger;
	int			**tbf;
	int			*ray_buffer;
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	int			o_no;
	int			o_so;
	int			o_ea;
	int			o_we;
	int			have_map;
	int			is_map;
	int			emp;
	int			cut;
}				t_data;

int		is_whitespace(int c);
int		get_elements_from_file(char *map_name, t_data *map);
int		ft_parse_path(char *line);
int		valid_value(char v);
int		ft_map(t_data *map_data, char *line, int i);
int		is_empty_line(char *line);
int		parse_full_map(t_data *map_data);
int		is_map_border(t_data *map_data, int j, int i);
int		wall_space(char e);
int		len_x(t_data *map_data, int n);
int		get_player_pos(t_data *data);
int		create_trgb(int t, int r, int g, int b);
int		main_loop(t_data *mlx);
int		**create_buffer(int width, int height);
int		ft_get_path(char *line, t_data *data);
int		ft_get_cell_floor(t_data *data, char *line);
int		check_floor_cell(char *line);
int		ft_get_color(char *str);
int		path_error_handle(t_data *data, char *line);
int		check_mapline(char *line, t_data *data);
int		fc_check(char *line);
int		is_player(char p);
int		parse_file(char *map_name, t_data *data);
int		invalid_filename(char *filename);

int		press_key(int k, t_data *data);
int		release_key(int k, t_data *data);
void	key_init(t_data *data);

void	error_txt(char *txt);

void	move_key(t_data *data);
void	rot_left_right(t_data *data, double rot);
void	m_front_back(t_data *data, double move);
void	m_left_right(t_data *d, double move);

void	init_raycasting(t_data *data, int x);
void	side_dist(t_data *data);
void	ft_dda(t_data *data);
void	line_height(t_data *data);
void	coloring(t_data *data);
void	cast_texture(t_data *data);
void	increase_texture(t_data *data, int x);

void	draw_buffer(t_data *data);
void	update_data(t_data *data);

char	*ft_partmap(char *line, int i);

void	map_handler(int fd, t_data *data);
void	create_map(t_data *data, int y, int x);

void	data_init(t_data *data);

char	**map_from_string(char *str, t_data *data);

int		load_image(t_data *data, int *tex, char *path, t_img *img);
int		load_textures(t_data *data);

void	set_spawn(t_data *data);
void	free_and_exit(char *msg, t_data *data);
void	tabulation_handler(char **line);

void	error_code(int error);
void	free_elements(t_data *data);
void	draw_2d_wall(t_data *data);

t_data	*get_data(t_data *data);

#endif
