/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_speed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:56:16 by lquehec           #+#    #+#             */
/*   Updated: 2024/05/02 16:56:21 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_speed(t_game *game, t_player *player, double *speed)
{
	int		moves;

	moves = 0;
	if (player->move & M_SPRINT)
		*speed = game->settings.sprint_speed;
	else
		*speed = player->speed;
	if (player->move & M_UP)
		moves++;
	if (player->move & M_DOWN)
		moves++;
	if (player->move & M_LEFT)
		moves++;
	if (player->move & M_RIGHT)
		moves++;
	if ((player->move & M_UP) && (player->move & M_DOWN))
		moves -= 2;
	if ((player->move & M_LEFT) && (player->move & M_RIGHT))
		moves -= 2;
	if (moves > 1)
		*speed /= sqrt(2) * (moves - 1);
	return ;
}
