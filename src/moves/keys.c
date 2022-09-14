#include "cub.h"

void	move_up(t_data *data)
{
	//if (data->game->map[(int)(data->player->y -  PLAYER_SPEED)][(int)data->player->x] != WALL)
	if (data->player->y != WIN_HEIGHT / data->game->map_height)
		data->player->y -= data->player->dy;
}

void	move_down(t_data *data)
{
	//if (data->game->map[(int)(data->player->y + PLAYER_SPEED)][(int)data->player->x] != WALL)
	if (data->player->y != data->game->map_height - WIN_HEIGHT / data->game->map_height)
		data->player->y += data->player->dy;
}

void	move_left(t_data *data)
{
	//if (data->game->map[(int)data->player->y][(int)(data->player->x - PLAYER_SPEED)] != WALL)
	if (data->player->x != WIN_WIDTH / data->game->map_width)
		data->player->x -= data->player->dx;
}

void	move_right(t_data *data)
{
	// if (data->game->map[(int)data->player->y][(int)(data->player->x + PLAYER_SPEED)] != WALL)
	if (data->player->x != data->game->map_width - WIN_WIDTH / data->game->map_width)
		data->player->x += data->player->dx;
}

void	rotate_left(t_data *data)
{
	data->player->angle -= ROTATE_SPEED;
	if (data->player->angle < 0)
		data->player->angle = 2 * PI + data->player->angle;
}

void	rotate_right(t_data *data)
{
	data->player->angle += ROTATE_SPEED;
	if (data->player->angle > 2 * PI)
		data->player->angle -= 2 * PI;
}

void	key_handler(int key, t_data *data)
{
	data->player->angle = 60 * (PI / 180);
	data->player->dx = PLAYER_SPEED * cos(data->player->angle);
	data->player->dy = PLAYER_SPEED * sin(data->player->angle);
	if (key == W)
		move_up(data);
	else if (key == S)
		move_down(data);
	else if (key == D)
		move_left(data);
	else if (key == A)
		move_right(data);
	else if (key == RIGHT)
		rotate_right(data);
	else if (key == LEFT)
		rotate_left(data);
}
