/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:21:02 by aboudoun          #+#    #+#             */
/*   Updated: 2022/09/28 16:55:30 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	is_valid(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_handler("Invalid texture");
	return (fd);
}

void	load_xpm(t_data *data, t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(data->mlx, path,
			&(img->width), &(img->height));
	if (img->img == NULL)
		error_handler("Invalid texture");
	img->addr = (int *) mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
	if (img->addr == NULL)
		error_handler("Invalid texture");
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
		load_xpm(data, north, data->game->north);
	if (is_valid(data->game->south))
		load_xpm(data, south, data->game->south);
	if (is_valid(data->game->west))
		load_xpm(data, west, data->game->west);
	if (is_valid(data->game->east))
		load_xpm(data, east, data->game->east);
	sprite->north = north;
	sprite->south = south;
	sprite->west = west;
	sprite->east = east;
	return (sprite);
}
