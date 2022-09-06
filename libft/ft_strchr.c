/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:58:22 by aboudoun          #+#    #+#             */
/*   Updated: 2021/11/09 18:17:34 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*ptr;

	ptr = (char *) str;
	i = 0;
	while (ptr[i] != (char)c)
	{
		if (!ptr[i])
			return (NULL);
		i++;
	}
	return (ptr + i);
}
