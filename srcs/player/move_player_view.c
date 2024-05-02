/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_view.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:59:02 by lquehec           #+#    #+#             */
/*   Updated: 2024/05/02 16:31:18 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_move_player_view_left(t_game *game, t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir.x;
	old_plane_x = player->plane.x;
	player->dir.x = (player->dir.x * game->settings.cos_neg_rot_speed) \
		- (player->dir.y * game->settings.sin_neg_rot_speed);
	player->dir.y = (old_dir_x * game->settings.sin_neg_rot_speed) \
		+ (player->dir.y * game->settings.cos_neg_rot_speed);
	player->plane.x = (player->plane.x * game->settings.cos_neg_rot_speed) \
		- (player->plane.y * game->settings.sin_neg_rot_speed);
	player->plane.y = (old_plane_x * game->settings.sin_neg_rot_speed) \
		+ (player->plane.y * game->settings.cos_neg_rot_speed);
	return (1);
}

int	ft_move_player_view_right(t_game *game, t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir.x;
	old_plane_x = player->plane.x;
	player->dir.x = (player->dir.x * game->settings.cos_rot_speed) \
		- (player->dir.y * game->settings.sin_rot_speed);
	player->dir.y = (old_dir_x * game->settings.sin_rot_speed) \
		+ (player->dir.y * game->settings.cos_rot_speed);
	player->plane.x = (player->plane.x * game->settings.cos_rot_speed) \
		- (player->plane.y * game->settings.sin_rot_speed);
	player->plane.y = (old_plane_x * game->settings.sin_rot_speed) \
		+ (player->plane.y * game->settings.cos_rot_speed);
	return (1);
}

int	ft_move_player_view_up(t_player *player)
{
	(void)player;
	return (1);
}

int	ft_move_player_view_down(t_player *player)
{
	(void)player;
	return (1);
}
