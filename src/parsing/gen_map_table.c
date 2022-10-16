/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_map_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:24:33 by majjig            #+#    #+#             */
/*   Updated: 2022/10/16 21:18:59 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	map_checker(char **map, int x, int y)
{
	if ((x == 0 || y == 0) || (map[y][x + 1] == ' ' || map[y][x + 1] == 0)
		|| (map[y - 1][x] == ' ' || map[y - 1][x] == 0) || (map[y + 1][x] == ' '
		|| map[y + 1][x] == 0) || (map[y][x - 1] == ' ' || map[y][x - 1] == 0))
	{
		x = 0;
		while (map[x])
			free(map[x++]);
		error_handler("Invalid map");
	}
}

static void	map_loop(char **map, int x, int y)
{
	int	player_count;

	player_count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr("NSWE", map[y][x]))
				if (++player_count > 1)
					error_handler("More than one player starting position");
			if (!ft_strchr("01 NWSE", map[y][x]))
				error_handler("Unknown item in map");
			if (map[y][x] == '0' || ft_strchr("NSWE", map[y][x]))
				map_checker(map, x, y);
			x++;
		}
		y++;
	}
	if (player_count == 0)
		error_handler("No player starting position");
}

static void	map_fix(size_t len, char **map)
{
	int		i;
	char	*tmp;

	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) < len)
		{
			tmp = ft_calloc(1, sizeof(char) * (1 + len - ft_strlen(map[i])));
			ft_memset(tmp, ' ', len - ft_strlen(map[i]));
			tmp[len - ft_strlen(map[i])] = 0;
			free(map[i]);
			map[i] = ft_strjoin(map[i], tmp);
			free(tmp);
		}
		i++;
	}
	map_loop(map, 0, 0);
}

char	**list_to_table(t_list *list)
{
	char	**map;
	int		size;

	size = ft_lstsize(list);
	map = (char **) ft_calloc(1, sizeof(char *) * (size + 1));
	ft_bzero(map, sizeof(char *) * (size + 1));
	size = 0;
	while (list)
	{
		map[size++] = ft_strdup(list->content);
		free(list->content);
		free(list);
		list = list->next;
	}
	return (map);
}

char	**gen_map(int fd, char *line)
{
	t_list	*list;
	char	**map;
	size_t	len;

	list = NULL;
	len = ft_strlen(line);
	ft_lstadd_back(&list, ft_lstnew(line));
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL || is_empty(line))
			break ;
		if (len < ft_strlen(line))
			len = ft_strlen(line);
		ft_lstadd_back(&list, ft_lstnew(line));
	}
	while (line)
	{
		if (is_empty(line))
			line = get_next_line(fd);
		else
			error_handler("Empty rows");
	}
	map = list_to_table(list);
	return (map_fix(len, map), map);
}
