#include "cub.h"



void	drw_column(t_data *data, int x, int dist, bool is_horizontal)
{
	// draw line from top to bottom aligned to center of WIN_HEIGHT

	int offsetX;
	int y = 0;
	if (is_horizontal)
		offsetX = (int)data->rays_x[x] % BOX_SIZE;
	else
		offsetX = (int)data->rays_y[x] % BOX_SIZE;
	while (y < WIN_HEIGHT / 2)
	{
		my_mlx_pixel_put(data->img_game, x, y, data->game->color_ceiling);
		y++;
	}
	y = WIN_HEIGHT - 1;
	while (y > WIN_HEIGHT / 2)
	{
		my_mlx_pixel_put(data->img_game, x, y, data->game->color_floor);
		y--;
	}
	//printf("floor_color: %d\n", data->game->color_floor);
	y = ((WIN_HEIGHT - dist) / 2);
	while (y <  (WIN_HEIGHT + ((int)(dist + .5))) / 2)
	{
		my_mlx_pixel_put(data->img_game, x, y, get_pixel(data->sprite->north, offsetX, y, dist));
		y++;
	}
}


void	draw_game(t_data *data)
{
	int i = 899;
	int col = 0;
	data->img_game->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->img_game->addr = (int *) mlx_get_data_addr(data->img_game->img, &data->img_game->bits_per_pixel, &data->img_game->line_length, &data->img_game->endian);
	while(i >= 0)
	{
		int dist = WIN_HEIGHT *  BOX_SIZE / (data->rays_dist[i] + 0.0001);
		if (dist >= WIN_HEIGHT)
			dist = WIN_HEIGHT - 1;
		if (dist <= 0)
			dist = 0;
		//unsigned transparency = (dist * 0xFF / (WIN_HEIGHT));
		drw_column(data, col++, dist, data->is_horizontal[i]);
		i--;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img_game->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img_game->img);
}
