#include"cub.h"

static double	get_vertical(t_data *data, double angle, int count)
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

static double	get_horizontal(t_data *data, double angle, int count)
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

void	get_distance(t_data *data)
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
