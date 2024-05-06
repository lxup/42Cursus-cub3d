/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_widget.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:56:41 by lquehec           #+#    #+#             */
/*   Updated: 2024/05/06 19:28:54 by lquehec          ###   ########.fr       */
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
		map_size.x / 40, 0x00FF00);
	return (1);
}

static void	ft_minimap_widget_2(t_game *game, t_vector map_pos, \
	t_vector map_size, t_minimap *minimap)
{
	minimap->pos.x = map_pos.x + (minimap->axe.x - game->player.pos.x + 5) \
		* map_size.x / 10;
	minimap->pos.y = map_pos.y + (minimap->axe.y - game->player.pos.y + 5) \
		* map_size.y / 10;
	minimap->size.x = map_size.x / 10;
	minimap->size.y = map_size.y / 10;
	if (minimap->pos.x < map_pos.x)
	{
		minimap->size.x -= (map_pos.x - minimap->pos.x);
		minimap->pos.x = map_pos.x;
	}
	if (minimap->pos.y < map_pos.y)
	{
		minimap->size.y -= (map_pos.y - minimap->pos.y);
		minimap->pos.y = map_pos.y;
	}
	if (minimap->pos.x + minimap->size.x > map_pos.x + map_size.x)
		minimap->size.x = map_pos.x + map_size.x - minimap->pos.x;
	if (minimap->pos.y + minimap->size.y > map_pos.y + map_size.y)
		minimap->size.y = map_pos.y + map_size.y - minimap->pos.y;
	if (minimap->size.x > 0 && minimap->size.y > 0)
		draw_items(game, minimap->pos, minimap->size, minimap->axe);
}

int	ft_minimap_widget(t_game *game, t_vector map_pos, t_vector map_size)
{
	t_minimap	minimap;

	ft_memset(&minimap, 0, sizeof(t_minimap));
	minimap.axe.y = game->player.pos.y - 5 - 1;
	while (++minimap.axe.y < game->player.pos.y + 5)
	{
		minimap.axe.x = game->player.pos.x - 5 - 1;
		while (++minimap.axe.x < game->player.pos.x + 5)
		{
			if (minimap.axe.y >= 0 \
				&& minimap.axe.y < game->map.size.y \
				&& minimap.axe.x >= 0 \
				&& minimap.axe.x < game->map.size.x)
			{
				ft_minimap_widget_2(game, map_pos, map_size, &minimap);
			}
		}
	}
	draw_player(game, map_pos, map_size);
	return (1);
}
