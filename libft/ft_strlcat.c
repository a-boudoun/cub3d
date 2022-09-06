/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:28:48 by aboudoun          #+#    #+#             */
/*   Updated: 2022/08/31 18:30:19 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	size_dest;
	size_t	size_src;

	size_dest = ft_strlen(dst);
	size_src = ft_strlen(src);
	i = 0;
	if (dstsize <= size_dest)
		return (dstsize + size_src);
	else
	{
		while (src[i] && size_dest + i < dstsize - 1)
		{
			dst[size_dest + i] = src[i];
			i++;
		}
		dst[size_dest + i] = '\0';
		return (size_dest + size_src);
	}	
}
