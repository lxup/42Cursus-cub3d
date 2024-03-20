/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:52:25 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/20 19:32:39 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_raycasting_wall(t_game *game)
{
	if (game->frame.side == 0)
		game->frame.perp_wall_dist = game->frame.side_dist.x - game->frame.delta_dist.x;
		// game->frame.perp_wall_dist = (game->frame.map.x - game->player.pos.x + (1 - game->frame.step.x) / 2) / game->frame.ray_dir.x;
	else if (game->frame.side == 1)
		game->frame.perp_wall_dist = game->frame.side_dist.y - game->frame.delta_dist.y;
		// game->frame.perp_wall_dist = (game->frame.map.y - game->player.pos.y + (1 - game->frame.step.y) / 2) / game->frame.ray_dir.y;
	game->frame.line_height = (int)(game->win.height / game->frame.perp_wall_dist);
	game->frame.draw_start = (int)(-game->frame.line_height / 2 \
		+ game->win.height / 2);
	if (game->frame.draw_start < 0)
		game->frame.draw_start = 0;
	if (game->frame.draw_start > game->win.height)
		game->frame.draw_start = game->win.height;
	game->frame.draw_end = (int)(game->frame.line_height / 2 + game->win.height / 2);
	if (game->frame.draw_end > game->win.height)
		game->frame.draw_end = game->win.height;
	if (game->frame.draw_end < 0)
		game->frame.draw_end = 0;
	if (game->frame.side == 0)
		game->frame.wall.x = (int)(game->player.pos.y \
			+ game->frame.perp_wall_dist * game->frame.ray_dir.y);
	else
		game->frame.wall.x = (int)(game->player.pos.x \
			+ game->frame.perp_wall_dist * game->frame.ray_dir.x);
	return (1);
}
