#include "cub.h"

void	move_up(t_data *data)
{
	if (data->game->map[(int)(data->player->y -  PLAYER_SPEED)][(int)data->player->x] != WALL)
		data->player->y -= PLAYER_SPEED;
}

void	move_down(t_data *data)
{
	if (data->game->map[(int)(data->player->y + PLAYER_SPEED)][(int)data->player->x] != WALL)
		data->player->y += PLAYER_SPEED;
}

void	move_left(t_data *data)
{
	if (data->game->map[(int)data->player->y][(int)(data->player->x - PLAYER_SPEED)] != WALL)
		data->player->x -= PLAYER_SPEED;
}

void	move_right(t_data *data)
{
	if (data->game->map[(int)data->player->y][(int)(data->player->x + PLAYER_SPEED)] != WALL)
		data->player->x += PLAYER_SPEED;
}

void	key_handler(int key, t_data *data)
{
	if (key == MOVE_UP)
		move_up(data);
	else if (key == MOVE_DOWN)
		move_down(data);
	else if (key == MOVE_LEFT)
		move_left(data);
	else if (key == MOVE_RIGHT)
		move_right(data);
}
