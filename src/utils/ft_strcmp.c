/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:55:30 by aboudoun          #+#    #+#             */
/*   Updated: 2022/09/28 16:43:04 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub.h"

bool	ft_strcmp(char *s1, char *s2)
{
	if (ft_strlen(s1) != ft_strlen(s2))
		return (false);
	return (!ft_strncmp(s1, s2, ft_strlen(s1)));
}
