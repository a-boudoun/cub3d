/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 12:25:32 by aboudoun          #+#    #+#             */
/*   Updated: 2021/11/07 12:25:37 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d_ptr;
	unsigned char	*s_ptr;
	size_t			i;

	d_ptr = (unsigned char *)dest;
	s_ptr = (unsigned char *)src;
	i = 0;
	if (!s_ptr && !d_ptr)
		return (NULL);
	while (n > i)
	{
		d_ptr[i] = s_ptr[i];
		i++;
	}
	return (dest);
}
