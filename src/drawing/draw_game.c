#include "cub.h"



void	drw_column(t_data *data, int x, int wall_height, bool is_horizontal)
{
	// draw line from top to bottom aligned to center of WIN_HEIGHT

	int offsetX;
	int y = 0;
	if (is_horizontal)
		offsetX = (int)data->rays_x[WIN_WIDTH - x] % BOX_SIZE;
	else
		offsetX = (int)data->rays_y[WIN_WIDTH - x] % BOX_SIZE;
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
	y = ((WIN_HEIGHT - wall_height) / 2);
	while (y <  (WIN_HEIGHT + wall_height) / 2)
	{
		my_mlx_pixel_put(data->img_game, x, y, get_pixel(data->sprite->north, offsetX, y, wall_height));
		// my_mlx_pixel_put(data->img_game, x, y, 0X0D8E12);
		y++;
	}
}


void	draw_game(t_data *data)
{
	int i = WIN_WIDTH - 1;
	int col = 0;
	data->img_game->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->img_game->addr = (int *)mlx_get_data_addr(data->img_game->img, &data->img_game->bits_per_pixel, &data->img_game->line_length, &data->img_game->endian);
	while(i >= 0)
	{
		//printf("rays_dist[%d]: %f -- ", i, data->rays_dist[i]);
		int wall_height = WIN_HEIGHT *  BOX_SIZE / (data->rays_dist[i] + 0.0001);
		//printf("dist: %d\n", dist);
		if (wall_height >= WIN_HEIGHT)
			wall_height = WIN_HEIGHT;
		if (wall_height <= 0)
			wall_height = 0;
		//unsigned transparency = (dist * 0xFF / (WIN_HEIGHT));
		drw_column(data, col++, wall_height, data->is_horizontal[i]);
		i--;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img_game->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img_game->img);
}
