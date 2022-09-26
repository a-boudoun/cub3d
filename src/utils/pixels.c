#include "cub.h"

unsigned int get_pixel(t_img *img, int x, int y, double wall_height)
{
	int color;

	y = ((y - (((WIN_HEIGHT - wall_height) / 2))) * BOX_SIZE) / wall_height;
	color = img->addr[y * (img->line_length / 4) + x];
	return (color);
}
