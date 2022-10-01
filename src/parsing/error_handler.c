/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:06:17 by aboudoun          #+#    #+#             */
/*   Updated: 2022/09/28 15:11:55 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub.h"

void	error_handler(char *message)
{
	ft_putstr_fd("Error", 2);
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}
