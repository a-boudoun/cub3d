#include"cub.h"


void drw_column(t_data *data, int x_b, int y_b, int color, double dist)
{
	int x;
	int y;

	y = 0;
	dist++;
	while (y < WIN_HEIGHT - dist)
	{
		x = 0;
		while (x < WIN_WIDTH / 104)
		{
			my_mlx_pixel_put(data->img_game, x + x_b, y + y_b, color);
			x++;
		}
		y++;
	}
}

void	draw_game(t_data *data)
{

	int i = 104;
	int x_b = 0;
	while(i >= 0)
	{
		drw_column(data, x_b, 0, 0xFFFFFF, data->rays[i]);
		i--;
		x_b += WIN_WIDTH / 104;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img_game->img, 0, 0);
}
