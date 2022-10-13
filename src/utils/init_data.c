/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:35:09 by aboudoun          #+#    #+#             */
/*   Updated: 2022/10/13 15:54:25 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_data(t_data *data)
{
	data->game = malloc(sizeof(t_game));
	ft_bzero(data->game, sizeof(t_game));
	data->player = malloc(sizeof(t_player));
	data->rays_dist = malloc(sizeof(double) * WIN_WIDTH);
	ft_bzero(data->player, sizeof(t_player));
	data->img = malloc(sizeof(t_img));
	data->img_game = malloc(sizeof(t_img));
	data->rays_x = malloc(sizeof(double) * WIN_WIDTH);
	data->rays_y = malloc(sizeof(double) * WIN_WIDTH);
	data->ray_angle = malloc(sizeof(double) * WIN_WIDTH);
	data->is_horizontal = malloc(sizeof(int) * WIN_WIDTH);
	ft_bzero(data->rays_x, sizeof(double) * WIN_WIDTH);
	ft_bzero(data->ray_angle, sizeof(double) * WIN_WIDTH);
	ft_bzero(data->rays_y, sizeof(double) * WIN_WIDTH);
}

void	init_images(t_data *data)
{
	data->img_game->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->img_game->addr = (int *)mlx_get_data_addr(data->img_game->\
img, &data->img_game->bits_per_pixel, &data->img_game->\
line_length, &data->img_game->endian);
	data->img->img = mlx_new_image(data->mlx, 6 * MINI, MINI * 6);
	data->img->addr = (int *)mlx_get_data_addr(data->img->img, &data->img->\
bits_per_pixel, &data->img->line_length, &data->img->endian);
}
