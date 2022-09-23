#include "cub.h"

void	change_position(t_data *data)
{
	if (data->player->angle < 0)
		data->player->angle = 2 * PI + data->player->angle;
	else if (data->player->angle > 2 * PI)
		data->player->angle -= 2 * PI;
	printf("player angle: %f\n", data->player->angle * 180 / PI);
	data->player->angle += data->player->rotation_direction * ROTATE_SPEED;
	data->player->x += data->player->walk_direction * cos(data->player->angle) * PLAYER_SPEED;
	data->player->y += data->player->walk_direction * sin(data->player->angle) * PLAYER_SPEED;
}

// void	rotate_left(t_data *data)
// {
// 	data->player->angle += ROTATE_SPEED;
// 	data->player->dx = cos(data->player->angle);
// 	data->player->dy = sin(data->player->angle);
// }

// void	rotate_right(t_data *data)
// {
// 	data->player->angle -= ROTATE_SPEED;
// 	data->player->dx = cos(data->player->angle);
// 	data->player->dy = sin(data->player->angle);
// }

void	key_handler(int key, t_data *data)
{
	if (key == W)
		data->player->walk_direction = 1;
	if (key == S)
		data->player->walk_direction = -1;
	if (key == A)
		data->player->turn_direction = -1;
	if (key == D)
		data->player->turn_direction = 1;
	if (key == LEFT)
		data->player->rotation_direction = 1;
	if (key == RIGHT)
		data->player->rotation_direction = -1;
	change_position(data);
}
