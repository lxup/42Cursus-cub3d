/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:42:01 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/22 17:56:10 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_minimap_size(t_game *game, t_vector *map_size, t_vector *map_pos)
{
	if (game->player.move & M_MAP)
	{
		map_size->x = game->win.height - 50;
		map_size->y = map_size->x;
		map_pos->x = game->win.width / 2 - map_size->x / 2;
		map_pos->y = 25;
	}
	else
	{
		map_size->x = game->win.width / 8;
		map_size->y = map_size->x;
		map_pos->x = game->win.width - map_size->x - 25;
		map_pos->y = 25;
	}
	return (1);
}

static int	ft_minimap_border(t_game *game, t_vector *map_pos, \
	t_vector *map_size)
{
	custom_mlx_draw_square(&game->win.frame, *map_pos, *map_size, 0x000000);
	(*map_pos).x += 10;
	(*map_pos).y += 10;
	(*map_size).x -= 20;
	(*map_size).y -= 20;
	return (1);
}

int	ft_minimap(t_game *game)
{
	t_vector	map_size;
	t_vector	map_pos;

	ft_minimap_size(game, &map_size, &map_pos);
	ft_minimap_border(game, &map_pos, &map_size);
	custom_mlx_draw_square(&game->win.frame, map_pos, map_size, 0x808080);
	ft_minimap_draw(game, map_pos, map_size);
	return (1);
}
