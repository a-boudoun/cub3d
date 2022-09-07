#include "cub.h"


char	**gen_map(int fd)
{
	t_list	*list;
	char	**map;
	size_t	len;
	char	*line;
	int		size;

	list = NULL;
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
		list = list->next;
	}
	return (map);
}
