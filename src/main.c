
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

int	key_press(int key,t_data *data)
{
	if (key == EXIT_KEY)
	{
		mlx_destroy_window(data -> mlx, data -> win);
		exit(0);
	}
	key_handler(key, data);
	return 0;
}

int next_frame(t_data *data)
{
	draw_map(data);
	mlx_clear_window(data -> mlx, data -> win);
	return 0;
}


int main(int ac, char **av)
{
	int fd;
	t_data data;

	fd = open_map(ac, av);
	data.game = get_map(fd);
	data.mlx = mlx_init();
	data.win = mlx_new_window(&data.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	data.sprite = check_elements_path(&data);
	data.sprite = check_elements_path(&data);
	data.player = malloc(sizeof(t_player));
	get_player_pos(&data);
	mlx_loop_hook(data.mlx, next_frame, &data);
	// printf("WE == |%s|\n", data.game->west);
	// printf("NO == |%s|\n", data.game->north);
	// printf("SO == |%s|\n", data.game->south);
	// printf("EA == |%s|\n", data.game->east);
	// printf("C  == |%d|\n", data.game->color_ceiling);
	// printf("F  == |%d|\n", data.game->color_floor);
	// int i = 0;
	//while (data.game -> map[i])
	mlx_key_hook(data.win, &key_press, &data);
	mlx_loop(&data.mlx);
	ft_clear(data.game);
	return (0);
}
