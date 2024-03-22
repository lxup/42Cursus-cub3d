/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:00:21 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/22 17:41:02 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_blocking(t_game *game, t_coord pos)
{
	if (pos.x < 0 || pos.x >= game->map.size.x || pos.y < 0 \
		|| pos.y >= game->map.size.y)
		return (1);
	if (game->map.content[(int)pos.y][(int)pos.x] == '1')
		return (1);
	return (0);
}

int	ft_move_collision(t_game *game, t_player *player, double speed, int move)
{
	t_coord	new_pos;

	new_pos.x = player->pos.x;
	new_pos.y = player->pos.y;
	if (move == M_UP)
	{
		new_pos.x += player->dir.x * speed;
		new_pos.y += player->dir.y * speed;
	}
	else if (move == M_DOWN)
	{
		new_pos.x -= player->dir.x * speed;
		new_pos.y -= player->dir.y * speed;
	}
	else if (move == M_LEFT)
	{
		new_pos.x -= player->plane.x * speed;
		new_pos.y -= player->plane.y * speed;
	}
	else if (move == M_RIGHT)
	{
		new_pos.x += player->plane.x * speed;
		new_pos.y += player->plane.y * speed;
	}
	return (is_blocking(game, new_pos));
}
