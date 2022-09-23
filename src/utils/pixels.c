#include "cub.h"

unsigned int get_pixel(t_img *img, int x, int y, double dist)
{
	char	*dst;
	int		color;

	dst = img->addr + ((y * img->line_length + x * (img->bits_per_pixel / 8)));
	color = *(unsigned int*)dst;
	if (dist < 0)
		dist = 0;
	if (dist > 255)
		dist = 255;
	color = (color & 0x00FFFFFF) | ((255 - (int)dist) << 24);
	return (color);
}