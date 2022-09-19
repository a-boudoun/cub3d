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
		my_mlx_pixel_put(data->img, beginX, beginY, 0xFF0000);
		beginX += deltaX;
		beginY += deltaY;
		--pixels;
	}
}

double	get_vertical(t_data *data, double angle)
{

	return (INFINITY);
}

double	get_horizontal(t_data *data, double angle)
{

	return (INFINITY);
}

static void	get_distance(t_data *data)
{
	double	hr_hit;
	double	vr_hit;
	int		count = 900;
	double	angle = data->player->angle - (FOV / 2);

	while (count--)
	{
		vr_hit = get_vertical(data, angle); // returns vertical wall hit distance
		hr_hit = get_horizontal(data, angle); // returns horizontal wall hit distance
		//printf("%f\n", (vr_hit > hr_hit) ? vr_hit : hr_hit);
		if (hr_hit < vr_hit)		//
			set_rays(data, hr_hit);	// setrays() adds the lowest distance to data->rays
		else						//
			set_rays(data, vr_hit); //
		printf("angle%f\n", angle * (180/PI));
		angle += FOV / WIN_WIDTH; // The angle increment for each ray
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
	draw_line(data, data->player->angle);
}
