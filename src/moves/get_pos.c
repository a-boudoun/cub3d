#include "cub.h"

static void	init_minimap(t_data *data)
{
	data->minimap = malloc(sizeof(t_minimap));
	ft_bzero(data->minimap, sizeof(t_minimap));
	data->minimap->p_box_height = WIN_HEIGHT / 6 / data->game->map_height;
	data->minimap->p_box_width = WIN_WIDTH / 6 / data->game->map_width;
	data->minimap->box_height = WIN_HEIGHT / 4 / data->game->map_height;
	data->minimap->box_width = WIN_WIDTH / 4 / data->game->map_width;
}

void	get_player_pos(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (data->game->map[y])
	{
		x = 0;
		while (data->game->map[y][x])
		{
			if (data->game->map[y][x] == INIT_POS)
			{
				data->player->x = x;
				data->player->y = y;
			}
			x++;
		}
		y++;
	}
	data->game->map_height = y;
	data->game->map_width = x;
	init_minimap(data);
}
