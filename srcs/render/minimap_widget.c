/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_widget.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:56:41 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/22 18:04:30 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	draw_items(t_game *game, t_vector pos, t_vector size, t_vector axe)
{
	if (game->map.content[axe.y][axe.x] == '1')
		custom_mlx_draw_square(&game->win.frame, pos, size, 0x000000);
	else if (game->map.content[axe.y][axe.x] == '2')
		custom_mlx_draw_square(&game->win.frame, pos, size, 0xFF0000);
	return (1);
}

static int	draw_player(t_game *game, t_vector map_pos, t_vector map_size)
{
	t_coord	pos_player;

	pos_player.x = map_pos.x + 5 * map_size.x / 10;
	pos_player.y = map_pos.y + 5 * map_size.y / 10;
	custom_mlx_draw_circle(&game->win.frame, pos_player, \
		map_size.x / 20, 0x00FF00);
	return (1);
}

int	ft_minimap_widget(t_game *game, t_vector map_pos, t_vector map_size)
{
	t_vector	pos;
	t_vector	size;
	t_vector	axe;

	axe.y = game->player.pos.y - 5 - 1;
	while (++axe.y < game->player.pos.y + 5)
	{
		axe.x = game->player.pos.x - 5 - 1;
		while (++axe.x < game->player.pos.x + 5)
		{
			if (axe.y >= 0 && axe.y < game->map.size.y && axe.x >= 0 \
				&& axe.x < game->map.size.x)
			{
				pos.x = map_pos.x + (axe.x - game->player.pos.x + 5) \
					* map_size.x / 10;
				pos.y = map_pos.y + (axe.y - game->player.pos.y + 5) \
					* map_size.y / 10;
				size.x = map_size.x / 10;
				size.y = map_size.y / 10;
				draw_items(game, pos, size, axe);
			}
		}
	}
	draw_player(game, map_pos, map_size);
	return (1);
}
