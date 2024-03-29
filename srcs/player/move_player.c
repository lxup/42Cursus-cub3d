/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:54:25 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/22 18:23:35 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_move_player_up(t_game *game, t_player *player, double speed)
{
	if (ft_move_collision(game, player, speed, M_UP))
		return (0);
	player->pos.x += player->dir.x * speed;
	player->pos.y += player->dir.y * speed;
	return (1);
}

static int	ft_move_player_down(t_game *game, t_player *player, double speed)
{
	if (ft_move_collision(game, player, speed, M_DOWN))
		return (0);
	player->pos.x -= player->dir.x * speed;
	player->pos.y -= player->dir.y * speed;
	return (1);
}

static int	ft_move_player_left(t_game *game, t_player *player, double speed)
{
	if (ft_move_collision(game, player, speed, M_LEFT))
		return (0);
	player->pos.x -= player->plane.x * speed;
	player->pos.y -= player->plane.y * speed;
	return (1);
}

static int	ft_move_player_right(t_game *game, t_player *player, double speed)
{
	if (ft_move_collision(game, player, speed, M_RIGHT))
		return (0);
	player->pos.x += player->plane.x * speed;
	player->pos.y += player->plane.y * speed;
	return (1);
}

int	ft_move_player(t_game *game, t_player *player)
{
	double	speed;

	if (player->move & M_SPRINT)
		speed = game->settings.sprint_speed;
	else
		speed = player->speed;
	if (player->move & M_UP)
		ft_move_player_up(game, player, speed);
	if (player->move & M_DOWN)
		ft_move_player_down(game, player, speed);
	if (player->move & M_LEFT)
		ft_move_player_left(game, player, speed);
	if (player->move & M_RIGHT)
		ft_move_player_right(game, player, speed);
	if (player->move & M_VIEW_LEFT)
		ft_move_player_view_left(game, player);
	if (player->move & M_VIEW_RIGHT)
		ft_move_player_view_right(game, player);
	if (player->move & M_VIEW_UP)
		ft_move_player_view_up(player);
	if (player->move & M_VIEW_DOWN)
		ft_move_player_view_down(player);
	return (1);
}
