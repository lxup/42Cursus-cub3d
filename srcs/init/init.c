/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:40:37 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/22 17:37:20 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_init_parsing(t_game *game)
{
	game->parsing.line = NULL;
	game->parsing.step = 0;
	game->parsing.succes = 0;
	return (1);
}

int	ft_init(t_game *game, char *file)
{
	ft_memset(game, 0, sizeof(t_game));
	ft_init_win(game);
	ft_init_map(game, file);
	ft_init_texture(game);
	ft_init_parsing(game);
	ft_init_frame(&game->frame);
	return (1);
}
