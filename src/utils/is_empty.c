/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:40:48 by aboudoun          #+#    #+#             */
/*   Updated: 2022/09/11 15:14:12 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"cub.h"

bool	is_empty(char *line)
{
	int	i;

	i = 0;
	if (ft_strlen(line) == 0)
		return true;
	while (ft_strchr(WHITE_SPACES, line[i]))
	{
		i++;
		if (line[i] == '\0')
			return (true);
	}
	return (false);
}
