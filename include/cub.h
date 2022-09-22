
#ifndef CUB_H
#define CUB_H

#define WHITE_SPACES " \t\r\f\v"

#include "../libft/libft.h"
#include "../gnl/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>
#include <fcntl.h>
#include <math.h>
#include "../mlx/mlx.h"


// KEYS

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
# define EMPTY '0'
# define WALL '1'
# define INIT_POS 'N'
# define NAME "cub3d"
# define WIN_WIDTH 900
# define WIN_HEIGHT 700
# define PI M_PI
# define ROTATE_SPEED 0.07
# define PLAYER_SPEED 2
# define FOV (PI / 3)
# define BOX_SIZE 6


typedef struct	s_img{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_sprite{
	int		x;
	int		y;
	int		texture;
	int		distance;
	void	*north_tex;
	void	*south_tex;
	void	*west_tex;
	void	*east_tex;
}				t_sprite;

typedef struct minimap{
	int		p_box_height;
	int		p_box_width;
	int		box;
}				t_minimap;

typedef struct s_player
{
	double	x;
	double	y;
	double	angle;
	double	dx;
	double	dy;

}				t_player;

typedef struct s_game {
	char			**map;
	int				map_height;
	int				map_width;
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	t_sprite		*sprite;
	int				color_floor;
	int				color_ceiling;
}				t_game;

typedef struct s_data
{
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
}				t_data;


void		error_handler(char *message);
t_game		*get_map(int fd);
bool		ft_strcmp(char *s1, char *s2);
char		**gen_map(int fd, char *line);
t_sprite	*check_elements_path(t_data *data);
int			count(char *str, char c);
void		set_rays(t_data *data, double dist, int index);
bool		is_empty(char *line);
void		draw_map(t_data *data);
void		key_handler(int key, t_data *data);
void		get_player_pos(t_data *data);
void		draw_game(t_data *data);
double		move_dist(t_data *data, double angle);
void		my_mlx_pixel_put(t_img *data, int x, int y, unsigned int color);

#endif

