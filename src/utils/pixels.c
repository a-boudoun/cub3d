#include "cub.h"

unsigned int get_pixel(t_img *img, int x, int y, double wall_height)
{
	unsigned int color;
	img += 0;
	x += 0;
	y += 0;


	// the brightness of the color is proportional to the wall_height / WIN_HEIGHT from the player
	int brightness = 0xFF -(int)(0xFF * (1 - wall_height / WIN_HEIGHT));
	color = (brightness << 16) | (brightness << 8) | brightness;
	return (color);
}
