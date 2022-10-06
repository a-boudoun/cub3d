/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:49:44 by aboudoun          #+#    #+#             */
/*   Updated: 2022/10/06 11:43:06 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, unsigned int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = (char *)data->addr + (y * data->line_length + x * \
			(data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_data *data, double b_x, double b_y)
{
	double	deltax;
	double	deltay;
	int		pixels;

	deltay = (b_y - sin(data->player->angle) * 9) - b_y;
	deltax = (b_x + cos(data->player->angle) * 9) - b_x;
	pixels = data->rays_dist[WIN_WIDTH / 2];
	deltax /= pixels;
	deltay /= pixels;
	while (pixels)
	{
		my_mlx_pixel_put(data->img, b_x, b_y, 0xFF1818);
		b_x += deltax;
		b_y += deltay;
		--pixels;
	}
}

void	drw_box(t_data *data, int x_b, int y_b, int color)
{
	// int	x;
	// int	y;

	// y = 0;
	// while (y < data->minimap->box)
	// {
	// 	x = 0;
	// 	while (x < data->minimap->box)
	// 	{
			my_mlx_pixel_put(data->img, x_b, y_b, color);
		// 	x++;
		// }
		// y++;
}

void	draw_map(t_data *data, double mini_p_x, double mini_p_y)
{
	int 	map_y;
	int 	map_x;
	int 	i;
	int		j;
	int		k;

	map_y = mini_p_y - MINI/2 * data->minimap->box;
	map_x = mini_p_x - MINI/2 * data->minimap->box;
	k = map_x;
	j = 0;
	while (j < MINI * data->minimap->box)
	{
		i = 0;
		map_x = k;
		while (i < MINI * data->minimap->box)
		{
			if (map_y < 0 || map_x < 0 || map_y / data->minimap->box > data->game->map_height - 1 || map_x / data->minimap->box  > data->game->map_width - 1 || data->game->map[map_y/ data->minimap->box ][map_x/ data->minimap->box ] == ' ')
				drw_box(data, i, j, 0x8758FF);
			else if (data->game->map[map_y / data->minimap->box ][map_x / data->minimap->box ] == WALL)
				drw_box(data, i, j, 0x8758FF);
			else if (data->game->map[map_y / data->minimap->box ][map_x / data->minimap->box ] == EMPTY || ft_strchr("NSWE", data->game->map[map_y / data->minimap->box ][map_x / data->minimap->box ]))
				drw_box(data, i, j, 0xD2DAFF);
			i++;
			map_x++;
		}
		j++;
		map_y++;
	}
	draw_line(data, MINI / 2 * 6, MINI / 2 * 6);
	get_distance(data);
}
