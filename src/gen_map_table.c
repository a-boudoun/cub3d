#include "cub.h"


static void map_checker(char **map)
{
	map += 0;
	return;
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
	map_checker(map);
}

char	**gen_map(int fd, char *line)
{
	t_list	*list;
	char	**map;
	size_t	len;
	int		size;

	* (ft_strchr(line, '\n')) = 0;
	len = ft_strlen(line);
	ft_lstadd_back(&list, ft_lstnew(line));
	//free(line);
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		* (ft_strchr(line, '\n')) = 0;
		if (len < ft_strlen(line))
			len = ft_strlen(line);
		ft_lstadd_back(&list, ft_lstnew(line));
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
