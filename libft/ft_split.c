/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 00:29:15 by aboudoun          #+#    #+#             */
/*   Updated: 2021/11/17 14:32:15 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	count_words(char const *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			words++;
		while (s[i] != c && s[i])
			i++;
	}
	return (words);
}

static char	*word_make(char *res, char const *s, int j, int word_len)
{
	int	i;

	i = 0;
	while (word_len > 0)
	{
		res[i] = s[j - word_len];
		i++;
		word_len--;
	}
	res[i] = '\0';
	return (res);
}

void	ft_free(char **word, int i)
{
	while (i >= 0)
	{
		i--;
		free(word[i]);
	}
	free(word);
}

static char	**ft_split_two(char **word, char const *s, char c, int c_w)
{
	int	i;
	int	j;
	int	word_len;

	i = 0;
	j = 0;
	word_len = 0;
	while (s[j] && i < c_w)
	{
		while (s[j] && s[j] == c)
			j++;
		while (s[j] && s[j] != c)
		{
			j++;
			word_len++;
		}
		word[i] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (word[i] == NULL)
			ft_free(word, i);
		word_make(word[i], s, j, word_len);
		word_len = 0;
		i++;
	}
	word[i] = NULL;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**word;
	int		c_w;

	if (s == NULL)
		return (NULL);
	c_w = count_words(s, c);
	word = (char **)malloc(sizeof(char *) * (c_w + 1));
	if (!word)
		return (NULL);
	ft_split_two(word, s, c, c_w);
	return (word);
}
