/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 12:24:14 by aboudoun          #+#    #+#             */
/*   Updated: 2022/08/24 19:08:56 by yaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*cpy_s1;
	unsigned char	*cpy_s2;
	size_t			i;

	cpy_s1 = (unsigned char *)s1;
	cpy_s2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (cpy_s1[i] && cpy_s2[i] && cpy_s1[i] == cpy_s2[i] && i < n - 1)
		i++;
	return (cpy_s1[i] - cpy_s2[i]);
}
