#include "cub.h"

void	set_rays(t_data *data, double dist, int index)
{
	if (data->rays_dist == NULL)
	{
		data->rays_dist = malloc(sizeof(int) * 900);
		ft_bzero(data->rays_dist, sizeof(int) * 900);
	}
	data->rays_dist[index] = (int)dist;
}
