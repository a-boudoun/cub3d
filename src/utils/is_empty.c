/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhspaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:40:48 by aboudoun          #+#    #+#             */
/*   Updated: 2022/09/10 17:47:27 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"cub.h"

bool	is_empty(char *line)
{
	int	i;

	i = 0;
	while (ft_strchr(" \n\t\r\f\v", line[i]))
	{
		i++;
		if (line[i] == '\0')
			return (true);
	}
	return (false);
}
