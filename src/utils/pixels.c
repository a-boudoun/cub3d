#include "cub.h"

unsigned int get_pixel(t_img *img, int x, int y, double wall_height)
{
	unsigned int color;


	color = *(unsigned int *)(img->addr + ((y % img->height) * img->line_length + (x % img->width) * (img->bits_per_pixel / 8)));

	return (color);
}
