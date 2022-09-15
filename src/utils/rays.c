#include "cub.h"

void	set_rays(t_data *data, double dist)
{
	static int	index = 0;

	if (data->rays == NULL)
	{
		data->rays = malloc(sizeof(double) * 105);
		ft_bzero(data->rays, sizeof(double) * 105);
	}
	data->rays[index++] = dist;
	if (index == 105)
		index = 0;
}
