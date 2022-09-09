/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:33:40 by aboudoun          #+#    #+#             */
/*   Updated: 2022/09/09 17:57:00 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
#define CUB_H

#define WHITE_SPACES " \t\v\f"

#include "../libft/libft.h"
#include "../gnl/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>
#include <fcntl.h>
#include "../mlx/mlx.h"


// KEYS
# define MOVE_LEFT 0
# define MOVE_DOWN 1
# define MOVE_RIGHT 2
# define EXIT 69
# define MOVE_UP 13
# define EXIT_KEY 53
# define PLAYER 'N'
# define EMPTY '0'
# define WALL '1'
# define NAME "cub3d"


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
}				t_data;


void	error_handler(char *message);
t_game	*get_map(int fd);
bool	ft_strcmp(char *s1, char *s2);
char	**gen_map(int fd, char *line);
t_sprite	*check_elements_path(t_data *data);

#endif

