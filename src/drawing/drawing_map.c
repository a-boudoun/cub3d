#include"cub.h"

void drw_box(t_data *data, int x_b, int y_b, int color)
{
	int x;
	int y;

	y = 0;
	while (y < BOX_Y)
	{
		x = 0;
		while (x < BOX_X)
		{
			mlx_pixel_put(data->mlx, data->win, x_b + x, y_b + y, color);
			x++;
		}
		y++;
	}
}

void drw_player(t_data *data, int x_b, int y_b, int color)
{
	int x;
	int y;

	y = 0;
	while (y < BOX_Y / 2)
	{
		x = 0;
		while (x < BOX_X / 2)
		{
			mlx_pixel_put(data->mlx, data->win, x_b + x, y_b + y, color);
			x++;
		}
		y++;
	}
}

void	draw_map(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (data->game->map[y])
	{
		x = 0;
		while (data->game->map[y][x])
		{
			if (data->game->map[y][x] == '1')
				drw_box(data, x * BOX_X, y * BOX_Y, 0xFFFFFF);
			else if (data->game->map[y][x] == EMPTY || data->game->map[y][x] == INIT_POS)
				drw_box(data, x * BOX_X, y * BOX_Y, data->game->color_floor);
			x++;
		}
		y++;
	}
	drw_player(data, data->player->x * BOX_X, data->player->y * BOX_Y, 0xFF0000);
}
