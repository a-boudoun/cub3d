#include "cub.h"

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
}
