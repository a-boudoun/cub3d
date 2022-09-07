/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:33:40 by aboudoun          #+#    #+#             */
/*   Updated: 2022/09/07 14:55:22 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
#define CUB_H

#include "../libft/libft.h"
#include "../gnl/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <mlx.h>


typedef struct s_sprite{
	int		x;
	int		y;
	int		texture;
	int		distance;
}				t_sprite;

typedef struct s_game {
	char		**map;
	int			map_height;
	int			map_width;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	t_sprite	*sprite;
	uint		color_floor;
	uint		color_ceiling;
}				t_game;

void	error_handler(char *message);

#endif
