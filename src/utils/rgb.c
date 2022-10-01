/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:41:53 by majjig            #+#    #+#             */
/*   Updated: 2022/09/28 16:45:01 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static bool	ft_isnumber(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

int	get_rgb(char *num)
{
	char	**tmp;
	int		len;
	int		r;
	int		g;
	int		b;

	tmp = ft_split(num, ',');
	len = -1;
	while (tmp[++len])
		if (!ft_isnumber(tmp[len]))
			error_handler("invalid color");
	if (len != 3)
		error_handler("invalid color");
	r = ft_atoi(tmp[0]);
	g = ft_atoi(tmp[1]);
	b = ft_atoi(tmp[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		error_handler("invalid color");
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	free(tmp);
	return ((r << 16) | (g << 8) | b);
}
