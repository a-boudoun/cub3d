/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:21:02 by aboudoun          #+#    #+#             */
/*   Updated: 2022/09/28 14:54:45 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub.h"

static int	is_valid(char *path)
{
	int fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_handler("Invalid texture");
	return (fd);
}

t_sprite	*check_elements_path(t_data *data)
{
	t_sprite	*sprite;
	t_img		*north;
	t_img		*south;
	t_img		*west;
	t_img		*east;

	sprite = (t_sprite *) malloc(sizeof(t_sprite));
	north = (t_img *) malloc(sizeof(t_img));
	south = (t_img *) malloc(sizeof(t_img));
	west = (t_img *) malloc(sizeof(t_img));
	east = (t_img *) malloc(sizeof(t_img));
	ft_bzero(sprite, sizeof(t_sprite));
	if (is_valid(data->game->north))
	{
		north->img = mlx_xpm_file_to_image(data->mlx, data->game->north, &(north->width), &(north->height));
		north->addr = (int*)mlx_get_data_addr(north->img, &(north->bits_per_pixel), &(north->line_length), &(north->endian));
	}
	if (is_valid(data->game->south))
	{
		south->img = mlx_xpm_file_to_image(data->mlx, data->game->south, &(south->width), &(south->height));
		south->addr = (int*)mlx_get_data_addr(south->img, &(south->bits_per_pixel), &(south->line_length), &(south->endian));
	}
	if (is_valid(data->game->west))
	{
		west->img = mlx_xpm_file_to_image(data->mlx, data->game->west, &(west->width), &(west->height));
		if (west->img == NULL)
			error_handler("Invalid texture");
		west->addr = (int*)mlx_get_data_addr(west->img, &(west->bits_per_pixel), &(west->line_length), &(west->endian));
	}
	if (is_valid(data->game->east))
	{
		east->img = mlx_xpm_file_to_image(data->mlx, data->game->east, &(east->width), &(east->height));
		east->addr = (int*)mlx_get_data_addr(east->img, &(east->bits_per_pixel), &(east->line_length), &(east->endian));
	}
	sprite->north = north;
	sprite->south = south;
	sprite->west = west;
	sprite->east = east;
	return (sprite);
}
