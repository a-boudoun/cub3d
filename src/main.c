
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

int next_frame(t_data *data)
{
	draw_map(data);
	draw_game(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return 0;
}

int	key_press(int key,t_data *data)
{
	if (key == ESC)
	{
		mlx_destroy_window(data -> mlx, data -> win);
		ft_clear(data -> game);
		exit(EXIT_SUCCESS);
	}
	keys_handler(key, data);
	next_frame(data);
	return 0;
}

int	key_release(int key, t_data *data)
{
	if (key == W || key == S)
		data->player->walk_direction = 0;
	if (key == A || key == D)
		data->player->turn_direction = 0;
	if (key == LEFT || key == RIGHT)
		data->player->rotation_direction = 0;
	return 0;
}


int main(int ac, char **av)
{
	int fd;
	t_data data;

	fd = open_map(ac, av);
	data.game = get_map(fd);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	data.sprite = check_elements_path(&data);
	data.sprite = check_elements_path(&data);
	data.player = malloc(sizeof(t_player));
	data.img = malloc(sizeof(t_img));
	data.img_game = malloc(sizeof(t_img));
	get_player_pos(&data);
	data.img_game->img = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
	data.img_game->addr = mlx_get_data_addr(data.img_game->img, &data.img_game->bits_per_pixel, &data.img_game->line_length, &data.img_game->endian);
	data.img->img = mlx_new_image(data.mlx, (data.minimap->box*(data.game->map_width)), data.game->map_height * data.minimap->box);
	data.img->addr = mlx_get_data_addr(data.img->img, &data.img->bits_per_pixel, \
		&data.img->line_length, &data.img->endian);
	data.player->angle = 60 * PI / 180;
	data.rays_x = malloc(sizeof(double) * WIN_WIDTH);
	data.rays_y = malloc(sizeof(double) * WIN_WIDTH);
	ft_bzero(data.rays_x, sizeof(double) * WIN_WIDTH);
	ft_bzero(data.rays_y, sizeof(double) * WIN_WIDTH);
	next_frame(&data);
	data.player->walk_direction = 0;
	data.player->turn_direction = 0;
	data.player->rotation_direction = 0;
	mlx_hook(data.win, 2, 0, &key_press, &data);
	mlx_hook(data.win, 3, 0, &key_release, &data);
	mlx_loop(data.mlx);
	ft_clear(data.game);
	return (0);
}
