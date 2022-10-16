/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collegion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:00:23 by aboudoun          #+#    #+#             */
/*   Updated: 2022/10/16 20:30:51 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	wall_collegion(t_data *data, double angle)
{
	if (data->is_horizontal[WIN_WIDTH / 2])
	{
		if ((angle > PI / 2 || angle < 3 * PI / 2) && move_dist(data, PI) - \
		50 > cos(angle) * PLAYER_SPEED)
			data->player->x = data->player->x + cos(angle) * PLAYER_SPEED;
		else if ((angle < PI / 2 || angle > 3 * PI / 2) && move_dist(data, 0) - \
		50 > cos(angle) * PLAYER_SPEED)
			data->player->x = data->player->x + cos(angle) * PLAYER_SPEED;
	}
	else if (!data->is_horizontal[WIN_WIDTH / 2])
	{
		if ((angle > 0 && angle <= PI) && move_dist(data, PI / 2) - 50 > \
		sin(angle) * PLAYER_SPEED)
			data->player->y = data->player->y - sin(angle) * PLAYER_SPEED;
		else if ((angle < 0 || angle > PI) && move_dist(data, 3 * PI / 2) - \
		50 > sin(angle) * PLAYER_SPEED)
			data->player->y = data->player->y - sin(angle) * PLAYER_SPEED;
	}
}
