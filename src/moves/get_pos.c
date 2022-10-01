/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:04:37 by aboudoun          #+#    #+#             */
/*   Updated: 2022/09/30 15:56:42 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	init_minimap(t_data *data)
{
	data->minimap = malloc(sizeof(t_minimap));
	ft_bzero(data->minimap, sizeof(t_minimap));
	data->minimap->p_box = 4;
	data->minimap->box = 6;
}

static void	init_angle(t_data *data)
{
	if (data->player->view == 'N')
		data->player->angle = (M_PI / 2);
	else if (data->player->view == 'S')
		data->player->angle = (3 * M_PI / 2);
	else if (data->player->view == 'W')
		data->player->angle = (M_PI);
	else if (data->player->view == 'E')
		data->player->angle = (2 * M_PI);
}

void	get_player_pos(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	init_minimap(data);
	while (data->game->map[y])
	{
		x = 0;
		while (data->game->map[y][x])
		{
			if (ft_strchr("NSEW", data->game->map[y][x]))
			{
				data->player->view = data->game->map[y][x];
				data->player->x = x * BOX_SIZE + BOX_SIZE / 2;
				data->player->y = y * BOX_SIZE + BOX_SIZE / 2;
			}
			x++;
		}
		y++;
	}
	init_angle(data);
	data->game->map_height = y;
	data->game->map_width = x;
}
