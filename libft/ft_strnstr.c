/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 12:24:30 by aboudoun          #+#    #+#             */
/*   Updated: 2022/08/31 18:33:49 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	b;
	char	*sr;
	char	*to_find;

	sr = (char *)haystack;
	to_find = (char *)needle;
	i = 0;
	b = 0;
	if (!to_find[b])
		return (sr);
	if (!sr[b])
		return (NULL);
	while (i < len)
	{
		b = 0;
		while (sr[i + b] == to_find[b] && to_find[b] && i + b < len)
		{
			if (!to_find[b + 1])
				return (&sr[i]);
			b++;
		}
		i++;
	}
	return (NULL);
}
