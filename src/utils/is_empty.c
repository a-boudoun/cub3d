/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:40:48 by aboudoun          #+#    #+#             */
/*   Updated: 2022/09/10 18:42:15 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"cub.h"

bool	is_empty(char *line)
{
	int	i;

	i = 0;
	if (ft_strlen(line) == 0)
		return true;
	while (ft_strchr(" \t\r\f\v", line[i]))
	{
		i++;
		if (line[i] == '\0')
			return (true);
	}
	return (false);
}
