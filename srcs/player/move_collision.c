/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:00:21 by lquehec           #+#    #+#             */
/*   Updated: 2024/05/06 19:25:30 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	is_blocking(t_game *game, t_coord *pos)
{
	if (pos->x < 0 || pos->x >= game->map.size.x || pos->y < 0 \
		|| pos->y >= game->map.size.y)
	{
		pos->x = game->player.pos.x;
		pos->y = game->player.pos.y;
	}
	else if (game->map.content[(int)pos->y][(int)pos->x] == '1')
	{
		if (game->map.content[(int)pos->y][(int)game->player.pos.x] == '1')
			pos->y = game->player.pos.y;
		if (game->map.content[(int)game->player.pos.y][(int)pos->x] == '1')
			pos->x = game->player.pos.x;
		if (game->map.content[(int)pos->y][(int)pos->x] == '1')
		{
			pos->x = game->player.pos.x;
			pos->y = game->player.pos.y;
		}
	}
}
