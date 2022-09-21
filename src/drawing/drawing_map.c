#include"cub.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, unsigned int color)
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

void draw_line(t_data *data, int count)
{
	double	beginX = data->player->x;
	double	beginY = data->player->y;
	double endX = data->rays_x[count];
	double endY = data->rays_y[count];
	double deltaX = endX - beginX; // 10
	double deltaY = endY - beginY; // 0
	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels; // 1
	deltaY /= pixels; // 0
	while (pixels)
	{
		my_mlx_pixel_put(data->img, beginX, beginY, 0xA10000);
		beginX += deltaX;
		beginY += deltaY;
		--pixels;
	}
}

double	get_vertical(t_data *data, double angle, int count)
{
	int	dof, mx, my;
	double rx,ry,x_move,y_move;
	double aTan;
	int px = data->player->x;
	int py = data->player->y;
	dof = 0;
	aTan= tan(angle);
	if (cos(angle) > 0.001)
	{
		rx = ((px / data->minimap->box_width)* data->minimap->box_width)  + data->minimap->box_width;
		ry = (px - rx)*aTan + py;
		x_move = data->minimap->box_width;
		y_move = -x_move*aTan;
	}
	else if (cos(angle) < -0.001)
	{
		rx = ((px / data->minimap->box_width)* data->minimap->box_width) - 0.0001;
		ry = (px - rx)*aTan + py;
		x_move = -data->minimap->box_width;
		y_move = -x_move*aTan;
	}
	else
	{
		dof = data->game->map_width;
	}
	while (dof < data->game->map_width)
	{
		mx = (int)(rx) / data->minimap->box_width;
		my = (int)(ry) / data->minimap->box_height;
		if (mx >= 0 && mx < data->game->map_width && my < data->game->map_height && my >= 0 && data->game->map[my][mx] == '1')
			dof = data->game->map_width;
		else
		{
			rx += x_move;
			ry += y_move;
			dof++;
		}
	}
	//printf("distance vertical[%f] = %f\n", (angle * 180) / PI, hypot((rx-px), (ry-py)));
	data->rays_x[count] = rx;
	data->rays_y[count] = ry;
	return(hypot((rx-px), (ry-py)) * fabs(cos(data->player->angle - angle)));
}

void	get_horizontal(t_data *data, double angle, int count)
{
	int	dof, mx, my;
	double rx,ry,x_move,y_move;
	double aTan;
	int px = data->player->x;
	int py = data->player->y;

	dof = 0;
	aTan= 1.0/tan(angle);
	if (sin(angle) > 0.001)
	{
		ry = ((py / data->minimap->box_height)* data->minimap->box_height)  - 0.0001;
		rx = (py - ry)*aTan + px;
		y_move = -data->minimap->box_height;
		x_move = -y_move*aTan;
	}
	else if (sin(angle) < -0.001)
	{
		ry = ((py / data->minimap->box_height)* data->minimap->box_height) + data->minimap->box_height;
		rx = (py - ry)*aTan + px;
		y_move = data->minimap->box_height;
		x_move = -y_move*aTan;
	}
	else
	{
		dof = data->game->map_height;
	}
	while (dof < data->game->map_height)
	{
		mx = (int)(rx) / data->minimap->box_width;
		my = (int)(ry) / data->minimap->box_height;
		if (mx >= 0 && mx < data->game->map_width && my < data->game->map_height && my >= 0 && data->game->map[my][mx] == '1')
			dof = data->game->map_height;
		else
		{
			rx += x_move;
			ry += y_move;
			dof++;
		}
	}
	//printf("distance horizontal[%f] = %f\n",((angle * 180) / PI), hypot((rx-px), (ry-py)));
	if (data->rays_dist[count] > hypot((rx-px), (ry-py)) * fabs(cos(data->player->angle - angle)))
	{
		data->rays_x[count] = rx;
		data->rays_y[count] = ry;
		data->rays_dist[count] = hypot((rx-px), (ry-py)) * fabs(cos(data->player->angle - angle));
	}
}

static void	get_distance(t_data *data)
{
	double	vr_hit;
	int		count = -1;
	double	angle = data->player->angle - (FOV / 2);

	while (++count < 900)
	{
		vr_hit = get_vertical(data, angle, count); // returns vertical wall hit distance
		set_rays(data, vr_hit, count);	// setrays() adds the lowest distance to data->rays
		get_horizontal(data, angle, count); // returns horizontal wall hit distance
		draw_line(data, count);
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
				drw_box(data, x * data->minimap->box_width, y * data->minimap->box_height, 0x8758FF);
			else if (data->game->map[y][x] == EMPTY || ft_strchr("NSWE", data->game->map[y][x]))
				drw_box(data, x * data->minimap->box_width, y * data->minimap->box_height, 0xD2DAFF);
			else
				drw_box(data, x * data->minimap->box_width, y * data->minimap->box_height, 0xFF000000);
			x++;
		}
		y++;
	}
	drw_player(data, data->player->x * data->minimap->box_width, data->player->y * data->minimap->box_height, 0x000ED5);
	get_distance(data);
}
