/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vertical.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:07:43 by aboudoun          #+#    #+#             */
/*   Updated: 2022/09/28 16:59:38 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub.h"

static void	init_get_vertical(t_distance *dist, t_data *data, double angle)
{
	int	px;
	int	py;

	py = data->player->y;
	px = data->player->x;
	if (cos(angle) > 0)
	{
		dist->rx = ((px / BOX_SIZE) * BOX_SIZE) + BOX_SIZE;
		dist->ry = (px - dist->rx) * (tan(angle)) + py;
		dist->x_move = BOX_SIZE;
		dist->y_move = -(dist->x_move) * tan(angle);
	}
	else if (cos(angle) < 0)
	{
		dist->rx = ((px / BOX_SIZE) * BOX_SIZE) - 0.0001;
		dist->ry = (px - dist->rx) * (tan(angle)) + py;
		dist->x_move = BOX_SIZE * (-1);
		dist->y_move = -(dist->x_move) * (tan(angle));
	}
	else
		dist->dof = data->game->map_width;
}

static void	check_map(t_data *data, t_distance *dist)
{
	int	mx;
	int	my;

	while (dist->dof < data->game->map_width)
	{
		mx = (int)(dist->rx) / BOX_SIZE;
		my = (int)(dist->ry) / BOX_SIZE;
		if (mx >= 0 && mx < data->game->map_width && my < \
data->game->map_height && my >= 0 && data->game->map[my][mx] == '1')
			dist->dof = data->game->map_width;
		else
		{
			dist->rx += dist->x_move;
			dist->ry += dist->y_move;
			dist->dof++;
		}
	}
}

double	get_vertical(t_data *data, double angle, int count)
{
	t_distance	*dist;
	int			px;
	int			py;

	px = data->player->x;
	py = data->player->y;
	dist = malloc(sizeof(t_distance));
	ft_bzero(dist, sizeof(t_distance));
	dist->dof = 0;
	init_get_vertical(dist, data, angle);
	check_map(data, dist);
	if (count == -1)
		return (hypot((dist->rx - px), (dist->ry - py)));
	data->rays_x[count] = dist->rx;
	data->rays_y[count] = dist->ry;
	data->is_horizontal[count] = false;
	data->ray_angle[count] = angle;
	return (hypot((dist->rx - px), (dist->ry - py)) * \
fabs(cos(data->player->angle - angle)));
}
