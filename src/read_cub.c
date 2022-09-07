
#include "cub.h"

bool ft_strcmp(char *s1, char *s2)
{
	if (ft_strlen(s1) != ft_strlen(s2))
		return (false);
	return ft_strncmp(s1, s2, ft_strlen(s1));
}

static void	add_to_game(t_game *game, int index, char **line)
{
	if (index == 0 && game -> north)
		error_handler("Error: multiple north sprites");
	else if (index == 1 && game -> south)
		error_handler("Error: multiple south sprites");
	else if (index == 2 && game -> west)
		error_handler("Error: multiple west sprites");
	else if (index == 3 && game -> east)
		error_handler("Error: multiple east sprites");
	else if (index == 0)
		game -> north = ft_strdup(line[1]);
	else if (index == 1)
		game -> south = ft_strdup(line[1]);
	else if (index == 2)
		game -> west = ft_strdup(line[1]);
	else if (index == 3)
		game -> east = ft_strdup(line[1]);
}


static bool add_type(char **line, t_game *game)
{
	static char	*valid_types[] = {"NO", "SO", "WE", "EA", "F", "C"};
	int			i;

	i = -1;
	while(++i < 6)
	{
		if (ft_strcmp(line[0], valid_types[i]))
		{
			add_to_game(game, i, line);
			return (true);
		}
	}
	return (false);
}


t_game *get_map(int fd)
{
	t_game	*game = (t_game *) malloc(sizeof(t_game));
	char	*line;
	int		i;
	char	**tmp;

	i = 0;
	ft_bzero(game, sizeof(t_game));
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		if (!ft_strncmp(line, "\n", 1))
			continue ;
		tmp = ft_split(line, ' ');
		add_type(tmp, game);
	}
	return (game);
}

