#include"cub.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void drw_box(t_data *data, t_img *img, int x_b, int y_b, int color)
{
	int x;
	int y;

	y = 0;
	while (y < WIN_HEIGHT / 4 / data->game->map_height)
	{
		x = 0;
		while (x < WIN_WIDTH / 4 / data->game->map_width)
		{
			my_mlx_pixel_put(img, x + x_b, y + y_b, color);
			x++;
		}
		y++;
	}
}

void drw_player(t_data *data, t_img *img, int x_b, int y_b, int color)
{
	int x;
	int y;

	y = 0;
	while (y < WIN_HEIGHT / 10 / data->game->map_height)
	{
		x = 0;
		while (x < WIN_WIDTH / 10 / data->game->map_width)
		{
			my_mlx_pixel_put(img, x + x_b, y + y_b, color);
			x++;
		}
		y++;
	}
}

void	draw_map(t_data *data)
{
	int x;
	int y;
	int box_x = WIN_WIDTH / 4 / data->game->map_width;
	int box_y = WIN_HEIGHT / 4 / data->game->map_height;

	data->img->img = mlx_new_image(data->mlx, (WIN_WIDTH), (WIN_HEIGHT));
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bits_per_pixel, \
		&data->img->line_length, &data->img->endian);
	y = 0;
	while (data->game->map[y])
	{
		x = 0;
		while (data->game->map[y][x])
		{
			if (data->game->map[y][x] == WALL)
				drw_box(data, data->img, x * box_x, y * box_y, 0xFF0000);
			else if (data->game->map[y][x] == EMPTY || ft_strchr("NSWE", data->game->map[y][x]))
				drw_box(data, data->img, x * box_x, y * box_y, 0xFFFFFF);
			x++;
		}
		y++;
	}
	drw_player(data, data->img, data->player->x * box_x, data->player->y * box_y, 0x000ED5);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}
