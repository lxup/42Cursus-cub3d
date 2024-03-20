/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:40:37 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/20 12:00:35 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_init_parsing(t_game *game)
{
	game->parsing.line = NULL;
	game->parsing.no = 0;
	game->parsing.so = 0;
	game->parsing.we = 0;
	game->parsing.ea = 0;
	game->parsing.s = 0;
	game->parsing.f = 0;
	game->parsing.c = 0;
	game->parsing.map = 0;
	game->parsing.succes = 0;
	return (1);
}

static int	ft_init_frame(t_game *game)
{
	ft_init_image(game, &game->frame.img);
	ft_init_coord(&game->frame.ray_dir, 0, 0);
	ft_init_coord(&game->frame.map, 0, 0);
	ft_init_coord(&game->frame.side_dist, 0, 0);
	ft_init_coord(&game->frame.delta_dist, 0, 0);
	ft_init_coord(&game->frame.step, 0, 0);
	ft_init_coord(&game->frame.wall, 0, 0);
	game->frame.hit = 0;
	return (1);
}

int	ft_init(t_game *game, char *file)
{
	ft_memset(game, 0, sizeof(t_game));
	ft_init_win(game);
	ft_init_map(game, file);
	ft_init_texture(game);
	ft_init_parsing(game);
	ft_init_frame(game);
	return (1);
}
