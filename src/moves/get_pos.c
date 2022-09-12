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
				break;
			x++;
		}
		y++;
	}
	data->player->x = x;
	data->player->y = y;
}