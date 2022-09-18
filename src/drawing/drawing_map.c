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
			my_mlx_pixel_put(data->img, beginX, beginY, 0xFF0000);
		else
			break;
		beginX += deltaX;
		beginY += deltaY;
		--pixels;
	}
}

static void	get_distance(t_data *data)
{
	double dx;
	double dy;
	int x;
	int y;

	data->rays_x = malloc(sizeof(double) * 900);
	data->rays_y = malloc(sizeof(double) * 900);
	ft_bzero(data->rays_x, sizeof(double) * 900);
	ft_bzero(data->rays_y, sizeof(double) * 900);
	x = (int)(data->player->x + 1);
	y =    ;
	while (data->game->map[(int)data->player->y][x] != WALL)
		x++;
		y += dy


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
			else
				drw_box(data, x * data->minimap->box_width, y * data->minimap->box_height, 0xFF000000);
			x++;
		}
		y++;
	}
	drw_player(data, data->player->x * data->minimap->box_width, data->player->y * data->minimap->box_height, 0x000ED5);
	get_distance(data);
	draw_line(data, data->player->angle - (PI / 6));
}
