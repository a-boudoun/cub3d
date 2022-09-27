#include"cub.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, unsigned int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = (char *)data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void drw_box(t_data *data, int x_b, int y_b, int color)
{
	int x;
	int y;

	y = 0;
	while (y <  6)
	{
		x = 0;
		while (x < 6)
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
	while (y < 3)
	{
		x = 0;
		while (x < 3)
		{
			my_mlx_pixel_put(data->img, x + x_b, y + y_b, color);
			x++;
		}
		y++;
	}
}

void draw_line(t_data *data, int count)
{
	(void)count;
	double	beginX = data->player->x / BOX_SIZE * 6;
	double	beginY = data->player->y / BOX_SIZE * 6;
	double endX = data->player->x / BOX_SIZE * 6 + cos(data->player->angle) * 6;
	double endY = data->player->y / BOX_SIZE * 6 - sin(data->player->angle) * 6;
	double deltaX = endX - beginX; // 10
	double deltaY = endY - beginY; // 0
	int pixels = data->rays_dist[count];
	deltaX /= pixels; // 1
	deltaY /= pixels; // 0
	while (pixels)
	{
		my_mlx_pixel_put(data->img, beginX, beginY, 0xFF1818);
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
		rx = ((px / BOX_SIZE)* BOX_SIZE)  + BOX_SIZE;
		ry = (px - rx)*aTan + py;
		x_move = BOX_SIZE;
		y_move = -x_move*aTan;
	}
	else if (cos(angle) < -0.001)
	{
		rx = ((px / BOX_SIZE)* BOX_SIZE) - 0.0001;
		ry = (px - rx)*aTan + py;
		x_move = -BOX_SIZE;
		y_move = -x_move*aTan;
	}
	else
	{
		dof = data->game->map_width;
	}
	while (dof < data->game->map_width)
	{
		mx = (int)(rx) / BOX_SIZE;
		my = (int)(ry) / BOX_SIZE;
		if (mx >= 0 && mx < data->game->map_width && my < data->game->map_height && my >= 0 && data->game->map[my][mx] == '1')
			dof = data->game->map_width;
		else
		{
			rx += x_move;
			ry += y_move;
			dof++;
		}
	}
	data->rays_x[count] = rx;
	data->rays_y[count] = ry;
	data->is_horizontal[count] = false;
	data->game->ray_angle[count] = angle;
	return(hypot((rx-px), (ry-py)) * fabs(cos(data->player->angle - angle)));
}

double	get_horizontal(t_data *data, double angle, int count)
{
	int	dof, mx, my;
	double rx,ry,x_move,y_move;
	double aTan;
	int px = data->player->x;
	int py = data->player->y;

	dof = 0;
	aTan= 1.0/tan(angle);
	if (sin(angle) > 0.00001)
	{
		ry = ((py / BOX_SIZE)* BOX_SIZE)  - 0.0001;
		rx = (py - ry)*aTan + px;
		y_move = -BOX_SIZE;
		x_move = -y_move*aTan;
	}
	else if (sin(angle) < -0.00001)
	{
		ry = ((py / BOX_SIZE)* BOX_SIZE) + BOX_SIZE;
		rx = (py - ry)*aTan + px;
		y_move = BOX_SIZE;
		x_move = -y_move*aTan;
	}
	else
	{
		dof = data->game->map_height;
	}
	while (dof < data->game->map_height)
	{
		mx = (int)(rx) / BOX_SIZE;
		my = (int)(ry) / BOX_SIZE;
		if (mx >= 0 && mx < data->game->map_width && my < data->game->map_height && my >= 0 && data->game->map[my][mx] == '1')
			dof = data->game->map_height;
		else
		{
			rx += x_move;
			ry += y_move;
			dof++;
		}
	}
	if (data->rays_dist[count] > hypot((rx-px), (ry-py)) * fabs(cos(data->player->angle - angle)))
	{
		data->rays_x[count] = rx;
		data->rays_y[count] = ry;
		data->is_horizontal[count] = true;
		data->rays_dist[count] = hypot((rx-px), (ry-py)) * fabs(cos(data->player->angle - angle));
	}
	return (hypot((rx-px), (ry-py)) * fabs(cos(data->player->angle - angle)));
}

static void	get_distance(t_data *data)
{
	double	vr_hit;
	int		count = -1;
	double	angle = data->player->angle - (FOV / 2);

	while (++count < WIN_WIDTH)
	{
		vr_hit = get_vertical(data, angle, count); // returns vertical wall hit distance
		set_rays(data, vr_hit, count);	// setrays() adds the lowest distance to data->rays
		get_horizontal(data, angle, count); // returns horizontal wall hit distance
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
				drw_box(data, x * 6, y * 6, 0x8758FF);
			else if (data->game->map[y][x] == EMPTY || ft_strchr("NSWE", data->game->map[y][x]))
				drw_box(data, x * 6, y * 6, 0xD2DAFF);
			else
				drw_box(data, x  * 6, y  * 6, 0xFF000000);
			x++;
		}
		y++;
	}
	drw_player(data, data->player->x / BOX_SIZE * 6 ,data->player->y / BOX_SIZE * 6, 0x000ED5);
	get_distance(data);
	draw_line(data, 450);
}
