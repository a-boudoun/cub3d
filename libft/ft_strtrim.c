/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:21:25 by aboudoun          #+#    #+#             */
/*   Updated: 2021/11/12 12:27:43 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_wherestart(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static int	ft_whereend(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[len - i - 1]) == 0)
			break ;
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*trimed_s;

	if (s1 == NULL)
		return (NULL);
	if (s1[0] == '\0')
		return (ft_strdup(""));
	if (set == NULL || set[0] == '\0')
		return (ft_strdup(s1));
	start = ft_wherestart(s1, set);
	if (s1[start] == '\0')
		return (ft_strdup(""));
	end = ft_whereend(s1, set);
	trimed_s = (char *)malloc(sizeof(char) * (end - start + 1));
	if (trimed_s == NULL)
		return (NULL);
	ft_strlcpy(trimed_s, s1 + start, end - start + 1);
	return (trimed_s);
}
