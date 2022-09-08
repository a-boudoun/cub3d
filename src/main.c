/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:33:22 by aboudoun          #+#    #+#             */
/*   Updated: 2022/09/08 18:55:08 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void ft_clear(t_game *game)
{
	free(game -> west);
	free(game -> north);
	free(game -> south);
	free(game -> east);
	int i = 0;
	while (game -> map[i])
		free(game -> map[i++]);
	free(game -> map);
	free(game -> sprite);

}

int open_map(int ac, char **av)
{
	int fd;

	if (ac != 2)
		error_handler("argument error");
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || !ft_strcmp(".cub", &av[1][ft_strlen(av[1]) - 4]))
		error_handler("invalid file");
	return (fd);
}

// int get_next_frame(t_data *data)
// {
// 	mlx_string_put(data->mlx, data->win, 10, 10, 0xFFFFFF, "Hello World !");
// 	data+=0;
// 	return (0);
// }

int main(int ac, char **av)
{
	int fd;
	t_data data;

	fd = open_map(ac, av);
	data.game = get_map(fd);
	printf("WE == %s\n", data.game->west);
	printf("NO == %s\n", data.game->north);
	printf("SO == %s\n", data.game->south);
	printf("EA == %s\n", data.game->east);
	printf("C  == %d\n", data.game->color_ceiling);
	printf("F  == %d\n", data.game->color_floor);
	int i = 0;
	while (data.game -> map[i])
		puts(data.game -> map[i++]);
	//data.mlx = mlx_init();
	// data.win = mlx_new_window(&data.mlx, 1000, 800, "cub3d");
	// mlx_loop_hook(&data.mlx, &get_next_frame, &data);
	// ft_clear(data.game);
	// mlx_loop(&data.mlx);
	return (0);
}
