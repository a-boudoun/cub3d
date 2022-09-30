/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:49:44 by aboudoun          #+#    #+#             */
/*   Updated: 2022/09/30 15:59:19 by aboudoun         ###   ########.fr       */
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

	deltay = (b_y - sin(data->player->angle) * 6) - b_y;
	deltax = (b_x + cos(data->player->angle) * 6) - b_x;
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
	int	x;
	int	y;

	y = 0;
	while (y < data->minimap->box)
	{
		x = 0;
		while (x < data->minimap->box)
		{
			my_mlx_pixel_put(data->img, x + x_b, y + y_b, color);
			x++;
		}
		y++;
	}
}

void	drw_player(t_data *data, double x_b, double y_b, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->minimap->p_box)
	{
		x = 0;
		while (x < data->minimap->p_box)
		{
			my_mlx_pixel_put(data->img, x + x_b, y + y_b, color);
			x++;
		}
		y++;
	}
	draw_line(data, x_b, y_b);
}

void	draw_map(t_data *data, double mini_p_x, double mini_p_y)
{
	int		x;
	int		y;

	y = 0;
	while (data->game->map[y])
	{
		x = 0;
		while (data->game->map[y][x])
		{
			if (data->game->map[y][x] == WALL)
				drw_box(data, x * data->minimap->box,
					y * data->minimap->box, 0x8758FF);
			else if (data->game->map[y][x] == EMPTY || \
					ft_strchr("NSWE", data->game->map[y][x]))
				drw_box(data, x * data->minimap->box,
					y * data->minimap->box, 0xD2DAFF);
			else
				drw_box(data, x * data->minimap->box,
					y * data->minimap->box, 0xFF000000);
			x++;
		}
		y++;
	}
	drw_player(data, mini_p_x, mini_p_y, 0x000ED5);
	get_distance(data);
}
