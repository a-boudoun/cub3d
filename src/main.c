/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:33:22 by aboudoun          #+#    #+#             */
/*   Updated: 2022/09/08 15:43:02 by majjig           ###   ########.fr       */
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
	if (fd < 0 || ft_strncmp(".cub", &av[1][ft_strlen(av[1] - 5)], 4))
		error_handler("invalid file");
	return (fd);
}

int get_next_frame(void * param)
{
	(void)param;
	//mlx_string_put(mlx_ptr, win_ptr, 10, 10, 0xFFFFFF, "Hello World !");
	return (0);
}

int main(int ac, char **av)
{
	int fd;
	fd = open_map(ac, av);
	t_game *game = get_map(fd);
	game += 0;
	void *ptr = mlx_init();
	mlx_new_window(ptr, 1000, 1000, "cub3d");
	mlx_loop_hook(ptr, &get_next_frame, NULL);
	ft_clear(game);
	mlx_loop(ptr);
	return (0);
}
