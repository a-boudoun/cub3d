/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:22:17 by aboudoun          #+#    #+#             */
/*   Updated: 2022/10/16 22:06:19 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define WHITE_SPACES " \t\r\f\v"

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <math.h>
# include <fcntl.h>
# include <math.h>
# include "../mlx/mlx.h"

// KEYS //
# define W 13
# define S 1
# define A 0
# define D 2
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define EXIT 69
////////////////////
# define EMPTY '0'
# define WALL '1'
# define NAME "cub3d"
# define WIN_WIDTH 1000
# define WIN_HEIGHT 800
# define PI M_PI
# define ROTATE_SPEED 0.07
# define PLAYER_SPEED 10
# define FOV 1.0471975512
# define MINI 20
# define VIEW_RANGE 1

typedef struct s_img{
	unsigned int	*img;
	int				*addr;
	int				bits_per_pixel;
	int				line_length;
	int				height;
	int				width;
	int				endian;
	bool			is_loaded;
}				t_img;

typedef struct s_sprite{
	int		x;
	int		y;
	int		distance;
	t_img	*north;
	t_img	*south;
	t_img	*west;
	t_img	*east;
}				t_sprite;

typedef struct minimap{
	int		p_box;
	int		box;
}				t_minimap;

typedef struct s_player
{
	void	*p_img;
	int		width;
	int		height;
	double	x;
	double	y;
	int		turn_direction;
	int		walk_direction;
	int		rotation_direction;
	double	angle;
	char	view;

}				t_player;

typedef struct s_game {
	char			**map;
	int				map_height;
	int				map_width;
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				color_floor;
	int				color_ceiling;
}				t_game;

typedef struct s_distance{
	double	rx;
	double	ry;
	double	x_move;
	double	y_move;
	int		dof;
}				t_distance;

typedef struct s_data
{
	int			box_size;
	void		*mlx;
	void		*win;
	t_game		*game;
	t_sprite	*sprite;
	t_player	*player;
	t_img		*img;
	t_img		*img_game;
	t_minimap	*minimap;
	double		*rays_dist;
	double		*rays_x;
	double		*rays_y;
	double		*ray_angle;
	bool		*is_horizontal;
}				t_data;

void			error_handler(char *message);
void			get_map(int fd, t_game *game, char*line);
bool			ft_strcmp(char *s1, char *s2);
char			**gen_map(int fd, char *line);
void			check_elements_path(t_data *data);
int				count(char *str, char c);
void			set_rays(t_data *data, double dist, int index);
bool			is_empty(char *line);
void			draw_map(t_data *data, double mini_p_x, double mini_p_y);
int				key_handler(int key, t_data *data);
void			get_player_pos(t_data *data);
void			draw_game(t_data *data);
double			move_dist(t_data *data, double angle);
void			my_mlx_pixel_put(t_img *data, int x, int y, unsigned int color);
unsigned int	get_pixel(t_img *img, int x, int y, double dist);
void			change_position(t_data *data);
void			get_distance(t_data *data);
double			get_horizontal(t_data *data, double angle, int count);
double			get_vertical(t_data *data, double angle, int count);
int				get_rgb(char *num);
void			init_data(t_data *data);
void			init_images(t_data *data);
void			circlular_minimap(int *img);
void			wall_collegion(t_data *data, double angle);
int				ft_clear(t_data *data);

#endif
