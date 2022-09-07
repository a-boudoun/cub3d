/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:33:22 by aboudoun          #+#    #+#             */
/*   Updated: 2022/09/07 15:55:54 by aboudoun         ###   ########.fr       */
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
	return (0);
}
