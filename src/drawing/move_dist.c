#include"cub.h"

static double	get_verticalm(t_data *data, double angle)
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
		rx = ((px / data->minimap->box)* data->minimap->box)  + data->minimap->box;
		ry = (px - rx)*aTan + py;
		x_move = data->minimap->box;
		y_move = -x_move*aTan;
	}
	else if (cos(angle) < -0.001)
	{
		rx = ((px / data->minimap->box)* data->minimap->box) - 0.0001;
		ry = (px - rx)*aTan + py;
		x_move = -data->minimap->box;
		y_move = -x_move*aTan;
	}
	else
	{
		dof = data->game->map_width;
	}
	while (dof < data->game->map_width)
	{
		mx = (int)(rx) / data->minimap->box;
		my = (int)(ry) / data->minimap->box;
		if (mx >= 0 && mx < data->game->map_width && my < data->game->map_height && my >= 0 && data->game->map[my][mx] == '1')
			dof = data->game->map_width;
		else
		{
			rx += x_move;
			ry += y_move;
			dof++;
		}
	}
	return(hypot((rx-px), (ry-py)));
}

static double	get_horizontalm(t_data *data, double angle)
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
		ry = ((py / data->minimap->box)* data->minimap->box)  - 0.0001;
		rx = (py - ry)*aTan + px;
		y_move = -data->minimap->box;
		x_move = -y_move*aTan;
	}
	else if (sin(angle) < -0.001)
	{
		ry = ((py / data->minimap->box)* data->minimap->box) + data->minimap->box;
		rx = (py - ry)*aTan + px;
		y_move = data->minimap->box;
		x_move = -y_move*aTan;
	}
	else
	{
		dof = data->game->map_height;
	}
	while (dof < data->game->map_height)
	{
		mx = (int)(rx) / data->minimap->box;
		my = (int)(ry) / data->minimap->box;
		if (mx >= 0 && mx < data->game->map_width && my < data->game->map_height && my >= 0 && data->game->map[my][mx] == '1')
			dof = data->game->map_height;
		else
		{
			rx += x_move;
			ry += y_move;
			dof++;
		}
	}
	return (hypot((rx-px), (ry-py)));
}
double	move_dist(t_data *data, double angle)
{
	double	vr_hit;
	double	hr_hit;

	vr_hit = get_verticalm(data, angle);
	hr_hit = get_horizontalm(data, angle);
	if (vr_hit < hr_hit && vr_hit)
		return(vr_hit);
	return(hr_hit);
}
