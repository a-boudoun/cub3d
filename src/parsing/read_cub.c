/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:55:13 by aboudoun          #+#    #+#             */
/*   Updated: 2022/10/16 21:19:00 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	add_to_game(t_game *game, int index, char **line)
{
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
		game -> color_floor = get_rgb(line[1]);
	else if (index == 5)
		game -> color_ceiling = get_rgb(line[1]);
}

static void	add_type(char **line, t_game *game)
{
	static char	*valid_types[] = {"NO", "SO", "WE", "EA", "F", "C"};
	int			i;
	char		*element;

	element = ft_strtrim(line[0], WHITE_SPACES);
	i = 0;
	while (i < 6)
	{
		if (ft_strcmp(element, valid_types[i]))
		{
			add_to_game(game, i, line);
			free(element);
			return ;
		}
		i++;
	}
	free(element);
	error_handler("Unknown type");
}

char	find_non_space(char *str)
{
	while (ft_strchr(WHITE_SPACES, *str))
		str++;
	if (*str == 'N')
	{
		if (*(str + 1) == 'O' && *(str + 2) == ' ')
			return (*str);
		return (-1);
	}
	return (*(str));
}

void	check_missing(char *line, t_game *game)
{
	if (!line)
		error_handler("Missing Map");
	if (game -> north == NULL || game -> south == NULL
		|| game -> east == NULL || game -> west == NULL)
		error_handler("missing TEXTURE");
	if (game -> color_ceiling == -1 || game -> color_floor == -1)
		error_handler("missing COLORS");
}

void	get_map(int fd, t_game *game, char *line)
{
	char	**tmp;

	tmp = ft_calloc(1, sizeof(char *) * 2);
	game -> color_ceiling = --game->color_floor;
	while (true)
	{
		line = get_next_line(fd);
		if (line && is_empty(line))
			free(line);
		if (line && is_empty(line))
			continue ;
		if (line == NULL || !ft_strchr("NSWEFC", find_non_space(line)))
			break ;
		free(line);
		line = ft_strtrim(line, WHITE_SPACES);
		tmp[0] = ft_substr(line, 0, (bool)(ft_strchr("SWEN", *line)) + 2);
		tmp[1] = ft_strtrim((line + 2), WHITE_SPACES);
		add_type(tmp, game);
		free(tmp[0]);
		free(tmp[1]);
		free(line);
	}
	check_missing(line, game);
	free(tmp);
	game -> map = gen_map(fd, line);
}
