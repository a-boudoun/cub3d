/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:06:17 by aboudoun          #+#    #+#             */
/*   Updated: 2022/09/10 15:05:46 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"cub.h"

void	error_handler(char *message)
{
	ft_putstr_fd("Error", 2);
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}