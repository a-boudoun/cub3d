#include "cub.h"

void	change_position(t_data *data)
{
	int move_x;
	int move_y;
	int turn_x;
	int turn_y;

	if (!data->player->walk_direction && !data->player->turn_direction && !data->player->rotation_direction)
		return ;
	printf("player angle: %f\n", data->player->angle * 180 / M_PI);
	data->player->angle += data->player->rotation_direction * ROTATE_SPEED;
	if (data->player->angle < 0)
		data->player->angle = 2 * PI + data->player->angle;
	else if (data->player->angle > 2 * PI)
		data->player->angle -= 2 * PI;
	move_x = data->player->walk_direction * cos(data->player->angle) * PLAYER_SPEED;
	move_y = data->player->walk_direction * sin(data->player->angle) * PLAYER_SPEED;
	turn_x = data->player->turn_direction * cos(data->player->angle + (PI / 2)) * PLAYER_SPEED;
	turn_y = data->player->turn_direction * sin(data->player->angle + (PI / 2)) * PLAYER_SPEED;
	if (move_dist(data, data->player->angle - (PI * (data->player->walk_direction == -1))) - 1 > hypot(move_x , move_y) && data->player->walk_direction)
	{
		data->player->x += move_x;
		data->player->y -= move_y;
	}
	if (move_dist(data, (data->player->angle + (PI / 2) * (data->player->turn_direction))) - 1 > hypot(turn_x , turn_y) && data->player->turn_direction)
	{
		data->player->x += turn_x;
		data->player->y -= turn_y;
	}
}

void	key_handler(int key, t_data *data)
{
	if (key == W)
		data->player->walk_direction = 1;
	if (key == S)
		data->player->walk_direction = -1;
	if (key == A)
		data->player->turn_direction = 1;
	if (key == D)
		data->player->turn_direction = -1;
	if (key == LEFT)
		data->player->rotation_direction = 1;
	if (key == RIGHT)
		data->player->rotation_direction = -1;
}
