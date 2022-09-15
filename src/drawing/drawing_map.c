#include"cub.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));

	if (*(int*)dst != color)
		*(unsigned int*)dst = color;
}

void drw_box(t_data *data, int x_b, int y_b, int color)
{
	int x;
	int y;

	y = 0;
	while (y <  data->minimap->box_height)
	{
		x = 0;
		while (x < data->minimap->box_width)
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
	while (y < data->minimap->p_box_height)
	{
		x = 0;
		while (x < data->minimap->p_box_width)
		{
			my_mlx_pixel_put(data->img, x + x_b, y + y_b, color);
			x++;
		}
		y++;
	}
}

void draw_line(t_data *data, double angle)
{
	if (data->player->angle + (PI / 6) < angle)
			return;
	double	beginX = data->player->x * data->minimap->box_width;
	double	beginY = data->player->y * data->minimap->box_height;
	double endX = data->player->x * data->minimap->box_width + cos(angle) * hypot(data->game->map_width * data->minimap->box_width, data->game->map_height * data->minimap->box_height);
	double endY = data->player->y * data->minimap->box_height - sin(angle) * hypot(data->game->map_width * data->minimap->box_width, data->game->map_height * data->minimap->box_height);
	double deltaX = endX - beginX; // 10
	double deltaY = endY - beginY; // 0
	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels; // 1
	deltaY /= pixels; // 0
	while (pixels)
	{
		if (data->game->map[(int)(beginY / data->minimap->box_height)][(int)(beginX / data->minimap->box_width)] != WALL)
			mlx_pixel_put(data->mlx, data->win, beginX, beginY, 0x33FF0000);
		else {
			//printf("%f\n", hypot((beginX / data->minimap->box_width) - data->player->x, (beginY / data->minimap->box_height) - data->player->y));
			set_rays(data, hypot((beginX / data->minimap->box_width) - data->player->x, (beginY / data->minimap->box_height) - data->player->y));
			break;
		}
		beginX += deltaX;
		beginY += deltaY;
		--pixels;
	}
	draw_line(data, angle + 0.01);
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
	draw_line(data, data->player->angle - (PI / 6));
}
