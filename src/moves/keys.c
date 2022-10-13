/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:08:28 by aboudoun          #+#    #+#             */
/*   Updated: 2022/10/13 15:32:05 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	init_steps(t_data *data, int *mx, int *my, int *tx)
{
	int	ty;

	*mx = data->player->walk_direction
		* cos(data->player->angle) * PLAYER_SPEED;
	*my = data->player->walk_direction
		* sin(data->player->angle) * PLAYER_SPEED;
	*tx = data->player->turn_direction
		* cos(data->player->angle + (PI / 2)) * PLAYER_SPEED;
	ty = data->player->turn_direction
		* sin(data->player->angle + (PI / 2)) * PLAYER_SPEED;
	return (ty);
}

static void	turn(t_data *data, int turn_x, int turn_y)
{
	double	wall_dist;

	wall_dist = hypot(turn_x, turn_y);
	if (move_dist(data, (data->player->angle + (PI / 2) * (data->player->\
turn_direction))) - 20 > wall_dist && data->player->turn_direction)
	{
		data->player->x += turn_x;
		data->player->y -= turn_y;
	}
}

static void	walk(t_data *data, int move_x, int move_y)
{
	double	wall_dist;
	double	dist;

	dist = move_dist(data, data->player->angle);
	wall_dist = hypot(move_x, move_y);
	if (move_dist(data, data->player->angle - (PI * (data->player->\
walk_direction == -1))) - 20 > wall_dist && data->player->walk_direction)
	{
		data->player->x += move_x;
		data->player->y -= move_y;
	}
	else if (data->player->walk_direction && dist < 30)
		wall_collegion(data, data->player->angle);
}

void	change_position(t_data *data)
{
	int	move_x;
	int	move_y;
	int	turn_x;
	int	turn_y;

	if (!data->player->walk_direction && !data->player->\
turn_direction && !data->player->rotation_direction)
		return ;
	data->player->angle += data->player->rotation_direction * ROTATE_SPEED;
	if (data->player->angle < 0)
		data->player->angle = 2 * PI + data->player->angle;
	else if (data->player->angle > 2 * PI)
		data->player->angle -= 2 * PI;
	turn_y = init_steps(data, &move_x, &move_y, &turn_x);
	turn(data, turn_x, turn_y);
	walk(data, move_x, move_y);
}

int	key_handler(int key, t_data *data)
{
	if (key == ESC)
		ft_clear(NULL);
	if (key == W)
		data->player->walk_direction = 1;
	if (key == S)
		data->player->walk_direction = -1;
	if (key == A)
		data->player->turn_direction = 1;
	if (key == D)
		data->player->turn_direction = -1;
	if (key == LEFT)
		data->player->rotation_direction = 1;
	if (key == RIGHT)
		data->player->rotation_direction = -1;
	return (0);
}
