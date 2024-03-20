/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_step.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:37:50 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/20 18:29:03 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_raycasting_step(t_game *game)
{
	if (game->frame.ray_dir.x < 0)
	{
		game->frame.step.x = -1;
		game->frame.side_dist.x = (game->player.pos.x - game->frame.map.x) \
			* game->frame.delta_dist.x;
	}
	else
	{
		game->frame.step.x = 1;
		game->frame.side_dist.x = (game->frame.map.x + 1.0 - game->player.pos.x)
			* game->frame.delta_dist.x;
	}
	if (game->frame.ray_dir.y < 0)
	{
		game->frame.step.y = -1;
		game->frame.side_dist.y = (game->player.pos.y - game->frame.map.y) \
			* game->frame.delta_dist.y;
	}
	else
	{
		game->frame.step.y = 1;
		game->frame.side_dist.y = (game->frame.map.y + 1.0 - game->player.pos.y)
			* game->frame.delta_dist.y;
	}
}
