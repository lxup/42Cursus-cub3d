/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:17:16 by lquehec           #+#    #+#             */
/*   Updated: 2024/05/06 19:29:17 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	minimap_player(t_game *game, t_vector map_pos, t_vector map_size)
{
	t_coord		pos;
	int			radius;

	pos.x = map_pos.x + game->player.pos.x * map_size.x / game->map.size.x;
	pos.y = map_pos.y + game->player.pos.y * map_size.y / game->map.size.y;
	radius = map_size.x / game->map.size.x / 4;
	custom_mlx_draw_circle(&game->win.frame, pos, radius, 0x00FF00);
	return (1);
}

static int	minimap_full(t_game *game, t_vector map_pos, t_vector map_size)
{
	t_vector	pos;
	t_vector	size;
	int			x;
	int			y;

	y = 0;
	while (y < game->map.size.y)
	{
		x = 0;
		while (x < game->map.size.x)
		{
			pos.x = map_pos.x + x * map_size.x / game->map.size.x;
			pos.y = map_pos.y + y * map_size.y / game->map.size.y;
			size.x = map_size.x / game->map.size.x;
			size.y = map_size.y / game->map.size.y;
			if (game->map.content[y][x] == '1')
				custom_mlx_draw_square(&game->win.frame, pos, size, 0x000000);
			else if (game->map.content[y][x] == '2')
				custom_mlx_draw_square(&game->win.frame, pos, size, 0xFF0000);
			x++;
		}
		y++;
	}
	minimap_player(game, map_pos, map_size);
	return (1);
}

int	ft_minimap_draw(t_game *game, t_vector map_pos, t_vector map_size)
{
	if (game->player.move & M_MAP)
		minimap_full(game, map_pos, map_size);
	else
		ft_minimap_widget(game, map_pos, map_size);
	return (1);
}
