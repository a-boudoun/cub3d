#include "cub.h"

void	circlular_minimap(int *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < MINI * 6)
	{
		x = 0;
		while (x < MINI * 6)
		{
			if ((hypot(x - MINI / 2 * 6, y - MINI / 2 * 6) > MINI / 2 * 6))
				img[y * MINI * 6 + x] = 0xFF000000;
			else if ((hypot(x - MINI / 2 * 6, y - MINI / 2 * 6) >= MINI / 2 * 6 - 1))
				img[y * MINI * 6 + x] = 0xFFFFFF;
			x++;
		}
		y++;
	}
}