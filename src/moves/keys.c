#include "cub.h"

void	key_handler(int key, t_data *data)
{
	if (key == MOVE_UP)
		data->player->y -= 0.4;
	else if (key == MOVE_DOWN)
		data->player->y += 0.4;
	else if (key == MOVE_LEFT)
		data->player->x -= 0.4;
	else if (key == MOVE_RIGHT)
		data->player->x += 0.4;
}
