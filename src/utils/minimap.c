/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:30:26 by majjig            #+#    #+#             */
/*   Updated: 2022/10/06 15:33:13 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	circlular_minimap(int *img)
{
	int	x;
	int	y;
	int	radius;

	radius = MINI / 2 * 6;
	y = 0;
	while (y < MINI * 6)
	{
		x = 0;
		while (x < MINI * 6)
		{
			if ((hypot(x - radius, y - radius) > radius))
				img[y * MINI * 6 + x] = 0xFF000000;
			else if ((hypot(x - radius, y - radius) >= radius - 1))
				img[y * MINI * 6 + x] = 0xFFFFFF;
			x++;
		}
		y++;
	}
}