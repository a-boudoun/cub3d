/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:46:13 by aboudoun          #+#    #+#             */
/*   Updated: 2022/09/30 15:00:40 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	drw_column(t_data *data, int x, int wall_height, int offsetx)
{
	int		y;
	bool	is_horizontal;

	is_horizontal = data->is_horizontal[WIN_WIDTH - x];
	y = (WIN_HEIGHT - wall_height) / 2;
	while (y++ < (WIN_HEIGHT + wall_height) / 2)
	{
		if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
		{
			if (is_horizontal && sin(data->ray_angle[WIN_WIDTH - x]) > 0)
				my_mlx_pixel_put(data->img_game, x, y, \
get_pixel(data->sprite->north, offsetx, y, wall_height));
			else if (is_horizontal && sin(data->ray_angle[WIN_WIDTH - x]) < 0)
				my_mlx_pixel_put(data->img_game, x, y, \
get_pixel(data->sprite->south, offsetx, y, wall_height));
			else if (!is_horizontal && cos(data->ray_angle[WIN_WIDTH - x]) > 0)
				my_mlx_pixel_put(data->img_game, x, y, \
get_pixel(data->sprite->east, offsetx, y, wall_height));
			else if (!is_horizontal && cos(data->ray_angle[WIN_WIDTH - x]) < 0)
				my_mlx_pixel_put(data->img_game, x, y, \
get_pixel(data->sprite->west, offsetx, y, wall_height));
		}
	}
}

void	drwa_wall_floor(t_data *data, int x, int wall_height)
{
	int	y;

	y = 0;
	while (y++ < (WIN_HEIGHT - wall_height) / 2)
		my_mlx_pixel_put(data->img_game, x, y, data->game->color_ceiling);
	y = (WIN_HEIGHT + wall_height) / 2;
	while (y++ < WIN_HEIGHT)
		my_mlx_pixel_put(data->img_game, x, y, data->game->color_floor);
}

void	draw_game(t_data *data)
{
	int	i;
	int	offsetx;
	int	col;
	int	wall_height;

	i = WIN_WIDTH - 1;
	col = 0;
	data->img_game->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->img_game->addr = (int *)mlx_get_data_addr(data->img_game->img, \
&data->img_game->bits_per_pixel, &data->img_game->line_length, \
&data->img_game->endian);
	while (i >= 0)
	{
		wall_height = WIN_HEIGHT * BOX_SIZE / (data->rays_dist[i] + 0.0001);
		drwa_wall_floor(data, col, wall_height);
		if (data->is_horizontal[i])
			offsetx = (int)data->rays_x[WIN_WIDTH - col] % BOX_SIZE;
		else
			offsetx = (int)data->rays_y[WIN_WIDTH - col] % BOX_SIZE;
		drw_column(data, col, wall_height, offsetx);
		i--;
		col++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img_game->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img_game->img);
}
