
#include "cub.h"

bool	ft_strcmp(char *s1, char *s2)
{
	if (ft_strlen(s1) != ft_strlen(s2))
		return (false);
	return !ft_strncmp(s1, s2, ft_strlen(s1));
}

int	get_RGB(char *num)
{
	char			**tmp;
	int				len;
	int	r;
	int	g;
	int	b;

	tmp = ft_split(num, ',');
	len = -1;
	while (tmp[++len]);
	if (len != 3)
		error_handler("invalid color");
	r = ft_atoi(tmp[0]);
	g = ft_atoi(tmp[1]);
	b = ft_atoi(tmp[2]);

	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		error_handler("invalid color");
	return ((r << 16) | (g << 8) | b);
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
	else if (index == 4 && game -> color_floor != -1)
		error_handler("Error: multiple floor colors");
	else if (index == 5 && game -> color_ceiling != -1)
		error_handler("Error: multiple ceiling colors");
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

	i = 0;
	while(i < 6)
	{
		if (ft_strcmp(line[0], valid_types[i]))
		{
			add_to_game(game, i, line);
		}
		i++;
	}
}


t_game	*get_map(int fd)
{
	t_game	*game;
	char	*line;
	int		i;
	char	**tmp;

	i = 0;
	game = (t_game *) malloc(sizeof(t_game));
	ft_bzero(game, sizeof(t_game));
	game -> color_ceiling = -1;
	game -> color_floor = -1;
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		if (ft_strcmp(line, "\n"))
			continue ;
		tmp = ft_split(line, ' ');
		add_type(tmp, game);
	}
	return (game);
}

