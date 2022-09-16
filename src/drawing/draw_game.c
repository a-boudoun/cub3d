#include"cub.h"



void	drw_column(t_data *data, int col, int color, double dist)
{
	int x = 0;
	int y = 0;

	//dist = (int) dist;
	y = WIN_HEIGHT - dist / 2;
	while (y > dist / 2)
	{
		x = 0;
		while (x < WIN_WIDTH / 105)
		{
			my_mlx_pixel_put(data->img_game, x + (col * (WIN_WIDTH / 104)), y, color);
			x++;
		}
		y--;
	}
}


void	draw_game(t_data *data)
{
	int i = 104;
	int col = 0;
	data->img_game->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->img_game->addr = mlx_get_data_addr(data->img_game->img, &data->img_game->bits_per_pixel, &data->img_game->line_length, &data->img_game->endian);
	while(i >= 0)
	{
		drw_column(data, col++, 0x909090 + ((int)data->rays[i] << 16), data->rays[i]);
		i--;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img_game->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img_game->img);
}
