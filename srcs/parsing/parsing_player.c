/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:01:14 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/21 10:40:54 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	set_dir_player(t_game *game, char c)
{
	if (ft_uppercase_char(c) == 'N')
	{
		ft_init_coord(&game->player.dir, 0, -1);
		ft_init_coord(&game->player.plane, ((double)game->win.width / \
			(double)game->win.height), 0);
	}
	else if (ft_uppercase_char(c) == 'S')
	{
		ft_init_coord(&game->player.dir, 0, 1);
		ft_init_coord(&game->player.plane, -((double)game->win.width / \
			(double)game->win.height), 0);
	}
	else if (ft_uppercase_char(c) == 'E')
	{
		ft_init_coord(&game->player.dir, 1, 0);
		ft_init_coord(&game->player.plane, 0, ((double)game->win.width / \
			(double)game->win.height));
	}
	else if (ft_uppercase_char(c) == 'W')
	{
		ft_init_coord(&game->player.dir, -1, 0);
		ft_init_coord(&game->player.plane, 0, -((double)game->win.width / \
			(double)game->win.height));
	}
	if (!game->player.dir.x && !game->player.plane.x)
		game->player.plane.x = 0.5 * game->player.dir.y;
	if (!game->player.dir.y && !game->player.plane.y)
		game->player.plane.y = -0.5 * game->player.dir.x;
	if (game->player.plane.x > 0 && game->player.plane.x < 0.5)
		game->player.plane.x = 1 - game->player.plane.x;
	if (game->player.plane.y > 0 && game->player.plane.y < 0.5)
		game->player.plane.y = 1 - game->player.plane.y;
	return (1);
}

int	ft_parsing_player(t_game *game)
{
	// ft_init_vector(&game->player.pos, game->map.spawn.x, game->map.spawn.y);
	set_dir_player(game, game->map.content[game->map.spawn.y][game->map.spawn.x]);
	game->map.content[game->map.spawn.y][game->map.spawn.x] = '0';
	ft_init_coord(&game->player.pos, game->map.spawn.x + 0.5, game->map.spawn.y + 0.5);
	game->player.speed = 0.05;
	game->player.rot_speed = 0.05;
	return (1);
}
