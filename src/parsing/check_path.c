/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:21:02 by aboudoun          #+#    #+#             */
/*   Updated: 2022/10/16 22:30:12 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	check_size(int height, int width)
{
	static int	h;
	static int	w;

	if (!h)
		h = height;
	if (!w)
		w = width;
	if (!w || !h || width != w || height != h || w != h)
		error_handler("texture should be square");
}

static int	is_valid(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_handler("Invalid texture");
	close(fd);
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
	check_size(img->height, img->width);
	img->is_loaded = true;
	free(path);
}

void	check_elements_path(t_data *data)
{
	t_img		*north;
	t_img		*south;
	t_img		*west;
	t_img		*east;

	data->sprite = ft_calloc(1, sizeof(t_sprite));
	north = ft_calloc(1, sizeof(t_img));
	south = ft_calloc(1, sizeof(t_img));
	west = ft_calloc(1, sizeof(t_img));
	east = ft_calloc(1, sizeof(t_img));
	if (is_valid(data->game->north))
		load_xpm(data, north, data->game->north);
	if (is_valid(data->game->south))
		load_xpm(data, south, data->game->south);
	if (is_valid(data->game->west))
		load_xpm(data, west, data->game->west);
	if (is_valid(data->game->east))
		load_xpm(data, east, data->game->east);
	data->box_size = north->height;
	data->player->p_img = mlx_xpm_file_to_image(data->mlx, "./textures/player.xpm\
", &data->player->width, &data->player->height);
	data->sprite->north = north;
	data->sprite->south = south;
	data->sprite->west = west;
	data->sprite->east = east;
}
