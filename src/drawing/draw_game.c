/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:46:13 by aboudoun          #+#    #+#             */
/*   Updated: 2022/10/17 17:05:58 by aboudoun         ###   ########.fr       */
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
		if (y >= WIN_HEIGHT)
			break ;
		else if (y < 0)
			y = 0;
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

void	drwa_wall_floor(t_data *data, int x, int wall_height)
{
	int	y;

	y = -1;
	while (++y < (WIN_HEIGHT - wall_height) / 2)
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
	while (i >= 0)
	{
		wall_height = WIN_HEIGHT / (data->rays_dist[i] / data->box_size);
		drwa_wall_floor(data, col, wall_height);
		if (data->is_horizontal[i])
			offsetx = (int)data->rays_x[WIN_WIDTH - col] % data->box_size;
		else
			offsetx = (int)data->rays_y[WIN_WIDTH - col] % data->box_size;
		drw_column(data, col, wall_height, offsetx);
		i--;
		col++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img_game->img, 0, 0);
}
