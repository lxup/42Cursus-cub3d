/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:12:03 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/21 12:06:16 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_init_game(t_game *game)
{
	ft_init_vector(&game->frame.mouse, (int)game->win.width / 2, (int)game->win.height / 2);
	
	// Init settings
	game->settings.fov = 1;
	game->settings.move_speed = 0.05;
	game->settings.rot_speed = 0.05;
	return (1);
}