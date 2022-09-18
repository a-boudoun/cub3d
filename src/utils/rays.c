#include "cub.h"

void	set_rays(t_data *data, double dist)
{
	static int	index = 0;

	if (data->rays_dist == NULL)
	{
		data->rays_dist = malloc(sizeof(double) * 899);
		ft_bzero(data->rays_dist, sizeof(double) * 899);
	}
	data->rays_dist[index++] = (dist) * WIN_HEIGHT / data->game->map_height;
	if (index == 900)
		index = 0;
}
