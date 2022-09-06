/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:04:38 by aboudoun          #+#    #+#             */
/*   Updated: 2021/11/09 18:17:57 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*ptr;

	if (c == '\0')
		return ((char *)str + ft_strlen(str));
	ptr = (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			ptr = (char *) str + i;
		i++;
	}
	return (ptr);
}
