/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:33:22 by aboudoun          #+#    #+#             */
/*   Updated: 2022/09/07 19:36:37 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int open_map(int ac, char **av)
{
	int fd;

	if (ac != 2)
		error_handler("argument error");
		fd = open(av[1], O_RDONLY);
	if (fd < 0 || ft_strncmp(".cub", &av[1][ft_strlen(av[1] - 5)], 4))
		error_handler("invalid file");
	return (fd);
}

int main(int ac, char **av)
{
	int fd;
	fd = open_map(ac, av);
	t_game *game = get_map(fd);
	game += 0;
	printf("WE == %s\n", game->west);
	printf("NO == %s\n", game->north);
	printf("SO == %s\n", game->south);
	printf("EA == %s\n", game->east);
	printf("C  == %d\n", game->color_ceiling);
	printf("F  == %d\n", game->color_floor);
	free(game -> west);
	free(game -> north);
	free(game -> south);
	free(game -> east);
	int i = 0;
	while (game -> map[i])
		free(game -> map[i++]);
	free(game -> map);
	free(game -> sprite);
	system("leaks cub3d");
	return (0);
}
