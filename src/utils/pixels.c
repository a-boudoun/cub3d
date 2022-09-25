#include "cub.h"

unsigned int get_pixel(t_img *img, int x, int y, double wall_height)
{
	unsigned int color;
	(void)wall_height;

	y = y - ((WIN_HEIGHT - wall_height) / 2);
	y *= 64 /  wall_height;

	color = *(unsigned int *)(img->addr + (y * (img->line_length / 4) + x));

	return (color);
}
