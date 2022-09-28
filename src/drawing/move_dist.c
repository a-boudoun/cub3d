#include"cub.h"

double	move_dist(t_data *data, double angle)
{
	double	vr_hit;
	double	hr_hit;

	vr_hit = get_vertical(data, angle, -1);
	hr_hit = get_horizontal(data, angle, -1);
	if (vr_hit < hr_hit && vr_hit)
		return(vr_hit);
	return(hr_hit);
}
