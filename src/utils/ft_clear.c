/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:04:24 by aboudoun          #+#    #+#             */
/*   Updated: 2022/10/16 22:12:57 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_clear_res(t_data *data)
{
	free(data -> game);
	free(data->rays_dist);
	free(data->ray_angle);
	free(data->rays_x);
	free(data->rays_y);
	free(data->is_horizontal);
	free(data->player);
	if (data -> win)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		free(data->mlx);
	}
	exit(EXIT_SUCCESS);
}

int	ft_clear(t_data *d)
{
	static t_data	*data = NULL;

	if (data == NULL)
		return (data = d, 0);
	if (data -> sprite)
	{
		if (data -> sprite -> west && data -> sprite -> west ->is_loaded)
			mlx_destroy_image(data->mlx, data -> sprite -> west -> img);
		if (data -> sprite -> north && data -> sprite -> north ->is_loaded)
			mlx_destroy_image(data->mlx, data -> sprite -> north -> img);
		if (data -> sprite -> south && data -> sprite -> south ->is_loaded)
			mlx_destroy_image(data->mlx, data -> sprite -> south -> img);
		if (data -> sprite -> east && data -> sprite -> east ->is_loaded)
			mlx_destroy_image(data->mlx, data -> sprite -> east -> img);
		if (data -> player -> p_img)
			mlx_destroy_image(data->mlx, data -> player -> p_img);
		if (data -> img_game)
			mlx_destroy_image(data->mlx, data -> img_game);
		free(data -> sprite);
	}
	ft_clear_res(data);
	return (0);
}
