#include "cub.h"

void	move_up(t_data *data)
{
	int px = (int)((data->player->x + data->player->dx * PLAYER_SPEED) / BOX_SIZE);
	int py = (int)((data->player->y - data->player->dy * PLAYER_SPEED) / BOX_SIZE);
	if (data->game->map[py][px] != WALL)
	{
		data->player->y -= (data->player->dy * PLAYER_SPEED) * BOX_SIZE;
		data->player->x += (data->player->dx * PLAYER_SPEED) * BOX_SIZE;
	}
}

void	move_down(t_data *data)
{
	int px = (int)((data->player->x - data->player->dx * PLAYER_SPEED) / BOX_SIZE);
	int py = (int)((data->player->y + data->player->dy * PLAYER_SPEED) / BOX_SIZE);
	if (data->game->map[py][px] != WALL)
	{
		data->player->y += (data->player->dy * PLAYER_SPEED) * BOX_SIZE;
		data->player->x -= (data->player->dx * PLAYER_SPEED) * BOX_SIZE;
	}
}

void	move_left(t_data *data)
{
	int px = (int)((data->player->x - data->player->dy * PLAYER_SPEED) / BOX_SIZE);
	int py = (int)(((data->player->y - data->player->dx * PLAYER_SPEED)) / BOX_SIZE);
	if (data->game->map[py][px] != WALL)
	{
		data->player->y -= (data->player->dx * PLAYER_SPEED) * BOX_SIZE;
		data->player->x -= (data->player->dy * PLAYER_SPEED) * BOX_SIZE;
	}
}

void	move_right(t_data *data)
{
	int px = (int)((data->player->x + data->player->dy * PLAYER_SPEED) / BOX_SIZE);
	int py = (int)(((data->player->y + data->player->dx * PLAYER_SPEED)) / BOX_SIZE);
	if (data->game->map[py][px] != WALL)
	{
		data->player->x += (data->player->dy * PLAYER_SPEED) * BOX_SIZE;
		data->player->y += (data->player->dx * PLAYER_SPEED) * BOX_SIZE;
	}

}

void	rotate_left(t_data *data)
{
	data->player->angle += ROTATE_SPEED;
	if (data->player->angle < 0)
		data->player->angle = 2 * PI + data->player->angle;
	data->player->dx = cos(data->player->angle);
	data->player->dy = sin(data->player->angle);
}

void	rotate_right(t_data *data)
{
	data->player->angle -= ROTATE_SPEED;
	if (data->player->angle > 2 * PI)
		data->player->angle -= 2 * PI;
	data->player->dx = cos(data->player->angle);
	data->player->dy = sin(data->player->angle);
}

void	key_handler(int key, t_data *data)
{
	if (key == W)
		move_up(data);
	else if (key == S)
		move_down(data);
	else if (key == A)
		move_left(data);
	else if (key == D)
		move_right(data);
	else if (key == RIGHT)
		rotate_right(data);
	else if (key == LEFT)
		rotate_left(data);
}
