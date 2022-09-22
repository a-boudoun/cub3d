#include "cub.h"

static void	init_minimap(t_data *data)
{
	data->minimap = malloc(sizeof(t_minimap));
	ft_bzero(data->minimap, sizeof(t_minimap));
	data->minimap->p_box_height = BOX_SIZE / 2;
	data->minimap->p_box_width = BOX_SIZE / 2;
	data->minimap->box_height = BOX_SIZE / (1 + (bool) (data->game->map_height * BOX_SIZE > WIN_HEIGHT));
	data->minimap->box_width = BOX_SIZE / (1 + (bool) (data->game->map_width * BOX_SIZE > WIN_WIDTH));
	if (data->minimap->box_height > data->minimap->box_width)
		data->minimap->box_height = data->minimap->box_width;
	else
		data->minimap->box_width = data->minimap->box_height;
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
				data->player->x = x * BOX_SIZE + BOX_SIZE / 2;
				data->player->y = y * BOX_SIZE + BOX_SIZE / 2;
			}
			x++;
		}
		y++;
	}
	data->game->map_height = y;
	data->game->map_width = x;
	init_minimap(data);
}
