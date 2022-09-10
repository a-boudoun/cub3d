#include "cub.h"

static void map_checker(char **map, int x, int y)
{
	if (x == 0 || y == 0)
		error_handler("Invalid map");
	if (map[y][x + 1] == ' ' || map[y][x + 1] == 0)
		error_handler("Invalid map");
	if (map[y - 1][x] == ' ' || map[y - 1][x] == 0)
		error_handler("Invalid map");
	if (map[y + 1][x] == ' ' || map[y + 1][x] == 0)
		error_handler("Invalid map");
	if (map[y][x - 1] == ' ' || map[y][x - 1] == 0)
		error_handler("Invalid map");
}

static void map_loop(char **map, int x, int y)
{
	int	player_count;

	player_count = 0;
	while(map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if (map[y][x] == 'N')
				if (++player_count > 1)
					error_handler("More than one player starting position");
			if (!ft_strchr("01 N", map[y][x]))
				error_handler("Unknown item in map");
			if (map[y][x] == '0' || map[y][x] == 'N')
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
			tmp = malloc(sizeof(char) * (len - ft_strlen(map[i])));
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

char	**gen_map(int fd, char *line)
{
	t_list	*list;
	char	**map;
	size_t	len;
	int		size;

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
	while(line)
	{
		if (is_empty(line))
			line = get_next_line(fd);
		else
			error_handler("Empty rows");
	}
	size = ft_lstsize(list);
	map = (char **) malloc(sizeof(char *) * (size + 1));
	ft_bzero(map, sizeof(char *) * (size + 1));
	size = 0;
	while (list)
	{
		map[size++] = ft_strdup(list->content);
		free(list->content);
		free(list);
		list = list->next;
	}
	map_fix(len, map);
	return (map);
}
