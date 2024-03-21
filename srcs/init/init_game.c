/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:12:03 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/21 20:52:46 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_init_game(t_game *game)
{
	ft_init_vector(&game->frame.mouse, (int)game->win.width / 2, (int)game->win.height / 2);
	
	// Init settings
	game->settings.fov = 1;
	game->settings.move_speed = 0.1;
	game->settings.rot_speed = 0.005;
	game->settings.cos_rot_speed = cos(game->settings.rot_speed);
	game->settings.sin_rot_speed = sin(game->settings.rot_speed);
	game->settings.cos_neg_rot_speed = cos(-game->settings.rot_speed);
	game->settings.sin_neg_rot_speed = sin(-game->settings.rot_speed);
	return (1);
}