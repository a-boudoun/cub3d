/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:42:35 by aboudoun          #+#    #+#             */
/*   Updated: 2022/09/28 16:45:41 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub.h"

void	get_distance(t_data *data)
{
	double	vr_hit;
	int		count;
	double	angle;

	angle = data->player->angle - (FOV / 2);
	count = -1;
	while (++count < WIN_WIDTH)
	{
		vr_hit = get_vertical(data, angle, count);
		set_rays(data, vr_hit, count);
		get_horizontal(data, angle, count);
		angle += FOV / WIN_WIDTH;
	}
}

double	move_dist(t_data *data, double angle)
{
	double	vr_hit;
	double	hr_hit;

	vr_hit = get_vertical(data, angle, -1);
	hr_hit = get_horizontal(data, angle, -1);
	if (vr_hit < hr_hit && vr_hit)
		return (vr_hit);
	return (hr_hit);
}
