#include"cub.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void drw_box(t_data *data, int x_b, int y_b, int color)
{
	int x;
	int y;

	y = 0;
	while (y <  WIN_HEIGHT / data->game->map_height -1)
	{
		x = 0;
		while (x < WIN_WIDTH / data->game->map_width - 1)
		{
			my_mlx_pixel_put(data->img, x + x_b, y + y_b, color);
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
	while (y < WIN_HEIGHT / 2 / data->game->map_height)
	{
		x = 0;
		while (x < WIN_WIDTH / 2 / data->game->map_width)
		{
			my_mlx_pixel_put(data->img, x + x_b, y + y_b, color);
			x++;
		}
		y++;
	}
}

void draw_line(t_data *data)
{
	double	beginX = data->player->x * data->minimap->box_width;
	double	beginY = data->player->y * data->minimap->box_height;
	double endX = data->player->x * data->minimap->box_width + cos(data->player->angle) * 30;
	double endY = data->player->y * data->minimap->box_height + sin(data->player->angle) * 30;
	double deltaX = endX - beginX; // 10
	double deltaY = endY - beginY; // 0
	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
//  pixels = sqrt((10 * 10) + (0 * 0)) = sqrt(100) = 10
	deltaX /= pixels; // 1
	deltaY /= pixels; // 0
	double pixelX = beginX;
	double pixelY = beginY;
	while (pixels)
	{
	    mlx_pixel_put(data->mlx, data->win, pixelX, pixelY, 0x00FF0000);
	    pixelX += deltaX;
	    pixelY += deltaY;
	    --pixels;
	}
}

void	draw_map(t_data *data)
{
	int x;
	int y;

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
				drw_box(data, x * data->minimap->box_width, y * data->minimap->box_height, 0xFCB000);
			else if (data->game->map[y][x] == EMPTY || ft_strchr("NSWE", data->game->map[y][x]))
				drw_box(data, x * data->minimap->box_width, y * data->minimap->box_height, 0xFFFFFF);
			x++;
		}
		y++;
	}
	drw_player(data, data->player->x * data->minimap->box_width, data->player->y * data->minimap->box_height, 0x000ED5);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	draw_line(data);
}
