#include "cub.h"

unsigned int get_pixel(t_img *img, int x, int y)
{
	return (img->addr[WIN_WIDTH * y + x]);
}