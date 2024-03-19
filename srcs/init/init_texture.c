/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:46:14 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/19 21:42:01 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_color(t_color *color)
{
	color->r = -1;
	color->g = -1;
	color->b = -1;
	color->a = -1;
	return (1);
}

int	ft_init_texture(t_game *game)
{
	ft_init_image(game, &game->textures.wall_no);
	ft_init_image(game, &game->textures.wall_so);
	ft_init_image(game, &game->textures.wall_we);
	ft_init_image(game, &game->textures.wall_ea);
	ft_init_image(game, &game->textures.sprite);
	init_color(&game->textures.ceiling);
	init_color(&game->textures.floor);
	// Add other textures here
	return (1);
}