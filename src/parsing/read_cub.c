/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:55:13 by aboudoun          #+#    #+#             */
/*   Updated: 2022/09/10 15:06:34 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	ft_isnumber(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	get_RGB(char *num)
{
	char	**tmp;
	int		len;
	int		r;
	int		g;
	int		b;

	if (count(num, ',') != 2)
		error_handler("Invalid color format");
	tmp = ft_split(num, ',');
	len = -1;
	while (tmp[++len])
	{
		if (!ft_isnumber(tmp[len]))
			error_handler("invalid color");
	}
	if (len != 3)
		error_handler("invalid color");
	r = ft_atoi(tmp[0]);
	g = ft_atoi(tmp[1]);
	b = ft_atoi(tmp[2]);

	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		error_handler("invalid color");
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	free(tmp);
	return ((r << 16) | (g << 8) | b);
}

static void	add_to_game(t_game *game, int index, char **line)
{
	*(ft_strchr(line[1], '\n')) = 0;
	if (index == 0 && game -> north)
		error_handler("multiple north sprites");
	else if (index == 1 && game -> south)
		error_handler("multiple south sprites");
	else if (index == 2 && game -> west)
		error_handler("multiple west sprites");
	else if (index == 3 && game -> east)
		error_handler("multiple east sprites");
	else if (index == 4 && game -> color_floor != -1)
		error_handler("multiple floor colors");
	else if (index == 5 && game -> color_ceiling != -1)
		error_handler("multiple ceiling colors");
	else if (index == 0)
		game -> north = ft_strdup(line[1]);
	else if (index == 1)
		game -> south = ft_strdup(line[1]);
	else if (index == 2)
		game -> west = ft_strdup(line[1]);
	else if (index == 3)
		game -> east = ft_strdup(line[1]);
	else if (index == 4)
		game -> color_floor = get_RGB(line[1]);
	else if (index == 5)
		game -> color_ceiling = get_RGB(line[1]);
}


static	void add_type(char **line, t_game *game)
{
	static char	*valid_types[] = {"NO", "SO", "WE", "EA", "F", "C"};
	int			i;
	char		*element;

	element = ft_strtrim(line[0], WHITE_SPACES);
	i = 0;
	while(i < 6)
	{
		if (ft_strcmp(element, valid_types[i]))
		{
			add_to_game(game, i, line);
		}
		i++;
	}
	free(element);
}

char	find_non_space(char *str)
{
	while(ft_strchr(WHITE_SPACES , *str))
		str++;
	if (*str == 'N')
	{
		if (*(str + 1) == 'O' && *(str + 2) == ' ')
			return *str;
		return (-1);
	}
	return (*(str));
}

t_game	*get_map(int fd)
{
	t_game	*game;
	char	*line;
	char	**tmp;

	tmp = malloc(sizeof(char *) * 2);
	game = (t_game *) malloc(sizeof(t_game));
	ft_bzero(game, sizeof(t_game));
	game -> color_ceiling = -1;
	game -> color_floor = -1;
	while (true)
	{
		line = get_next_line(fd);
		if (line && ft_strcmp(line, "\n"))
			free(line);
		if (line && ft_strcmp(line, "\n"))
			continue ;
		if (line == NULL || !ft_strchr("NSWEFC", find_non_space(line)))
				break;
		free(line);
		line = ft_strtrim(line, WHITE_SPACES);
		tmp[0] = ft_substr(line, 0, 2);
		tmp[1] = ft_strtrim((line + 2), WHITE_SPACES);
		add_type(tmp, game);
		free(tmp[0]);
		free(tmp[1]);
		free(line);
	}
	free(tmp);
	if (!line)
		error_handler("Missing Map");
	if (game -> north == NULL || game -> south == NULL || game -> east == NULL || game -> west == NULL)
		error_handler("missing TEXTURE");
	if (game -> color_ceiling == -1 || game -> color_floor == -1)
		error_handler("missing COLORS");
	return (game -> map = gen_map(fd, line), game);
}

